#include "../headers/diagram_generation.h"
#include "../../../computation/tools/gas.h"
#include <cmath> 
#include <fstream>
#include <sstream>
#include <iostream>
#include "../headers/error_window.h"
#include <QtWidgets/QMainWindow>
#include <QString>
#include <QStringList>
#include <QtCharts>

// --- PvDataPoints Implementation ---

PvDataPoints::PvDataPoints(std::string fileName)
{
    std::ifstream ifs(fileName);
    if(!ifs.is_open()) 
    {        
        // Assuming ErrorWindow is defined in help_window.h
        ErrorWindow* errorWindow = new ErrorWindow();
        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("File Error");
        errorWindow->setErrorText("Unable to read csv file. Rerun simulation and confirm the output");
        errorWindow->show();
    }
    else
    {
        // Read Headers
        std::string line;
        std::getline(ifs, line); // Read header line

        // Loop and get each line using getline to handle CSV properly
        while(std::getline(ifs, line))
        {
            QStringList qList_Line = QString::fromStdString(line).split(",");

            if(qList_Line.size() < 6)
            {
                // Assuming ErrorWindow is defined in help_window.h
                ErrorWindow* errorWindow = new ErrorWindow();
                errorWindow->setAttribute(Qt::WA_DeleteOnClose);
                errorWindow->setTitleText("File Error");
                errorWindow->setErrorText("Incorrect format in csv file. Rerun simulation and confirm the output");
                errorWindow->show();
            }
            else
            {
                this->pvDataPoints.push_back(PvDataPoint{qList_Line.at(0).toDouble(), qList_Line.at(2).toDouble()});
            }
        }
        if(this->pvDataPoints.size() < 4)
        {
            // Assuming ErrorWindow is defined in help_window.h
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("File Error");
            errorWindow->setErrorText("Incorrect format in csv file. Rerun simulation and confirm the output");
            errorWindow->show();
        }
        else
        {
            this->pointGeneration();
        }
    }
}

PvDataPoints::~PvDataPoints() {}

std::vector<PvDataPoint> PvDataPoints::get_pvDataPoints()
{
    return this->pvDataPoints;
}

void PvDataPoints::pointGeneration()
{

    double p1 = pvDataPoints.at(0).pressure;
    double p2   = pvDataPoints.at(1).pressure;
    double p3 = pvDataPoints.at(2).pressure;
    double p4 = pvDataPoints.at(3).pressure;


    double v1 = pvDataPoints.at(0).specific_volume;
    double v2   = pvDataPoints.at(1).specific_volume;
    double v3 = pvDataPoints.at(2).specific_volume;  
    double v4 = pvDataPoints.at(3).specific_volume;


    // Polytropic n calculation: n = log(p2/p1) / log(v1/v2)
    double n = std::log(p2 / p1) / std::log(v1 / v2);
    double constant = p1 * std::pow(v1, n);
    
    double step = (p2 - p1) / 30.0;

    // Generate 15 new points for compression (between index 0 and 1)
    int index = 1;

    for(double i_pressure = p1 + step; i_pressure < p2; i_pressure += step)
    {
        // eqn: specific_volume = (constant/pressure)^(1/n)
        double i_vol = std::pow(constant / i_pressure, 1.0 / n);
        
        this->pvDataPoints.insert(pvDataPoints.begin() + index, PvDataPoint{i_pressure, i_vol});
        index++;
    }
    
    
    // Polytropic n calculation: n = log(p4/p3) / log(v3/v4)
    n = std::abs(std::log(p4 / p3) / std::log(v3 / v4));
    constant = p3 * std::pow(v3, n);
    
    step = (p4 - p3) / 30.0;

    // Generate 15 points for expansion

    PvDataPoint finalPoint, secondLastPoint;
    finalPoint = pvDataPoints.at(pvDataPoints.size() - 1);
    secondLastPoint = pvDataPoints.at(pvDataPoints.size() - 2);
    this->pvDataPoints.pop_back();
    this->pvDataPoints.pop_back();

    for(double i_pressure = p3 + step; i_pressure > p4; i_pressure += step)
    {
        double i_vol = std::pow(constant / i_pressure, 1.0 / n);
        this->pvDataPoints.push_back(PvDataPoint{i_pressure, i_vol});
    }
    this->pvDataPoints.push_back(secondLastPoint);
    this->pvDataPoints.push_back(finalPoint);
}

QMainWindow *PvDataPoints::graphPvDiagram()
{
    QLineSeries *series = new QLineSeries();

    double minValX = std::numeric_limits<double>::max();
    double maxValX = std::numeric_limits<double>::lowest();
    double minValY = std::numeric_limits<double>::max();
    double maxValY = std::numeric_limits<double>::lowest();

    for(const auto& dataPoint : this->pvDataPoints)
    {
        series->append(dataPoint.specific_volume, dataPoint.pressure);

        if(dataPoint.specific_volume < minValX) minValX = dataPoint.specific_volume;
        if(dataPoint.specific_volume > maxValX) maxValX = dataPoint.specific_volume;
        if(dataPoint.pressure < minValY) minValY = dataPoint.pressure;
        if(dataPoint.pressure > maxValY) maxValY = dataPoint.pressure;
    }
    
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("pv Diagram");
    chart->legend()->hide();

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("specific volume (m^3 / kg)");
    
    double paddingX = (maxValX - minValX) * 0.01;
    axisX->setRange(minValX - paddingX, maxValX + paddingX); 
    
    axisX->applyNiceNumbers();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX); 

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("pressure (kPa)");
    
    double paddingY = (maxValY - minValY) * 0.01;
    axisY->setRange(minValY - paddingY, maxValY + paddingY);

    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *diagram = new QMainWindow();
    diagram->setAttribute(Qt::WA_DeleteOnClose);
    diagram->setCentralWidget(chartView);
    diagram->resize(1080, 720);
    diagram->show();

    return diagram;
}   


// --- TsDataPoints Implementation ---

TsDataPoints::TsDataPoints(std::string fileName)
{
    std::ifstream ifs(fileName);
    if(!ifs.is_open()) 
    {        
        ErrorWindow* errorWindow = new ErrorWindow();
        errorWindow->setAttribute(Qt::WA_DeleteOnClose);
        errorWindow->setTitleText("File Error");
        errorWindow->setErrorText("Unable to read csv file. Rerun simulation and confirm the output");
        errorWindow->show();
    }
    else
    {
        // Read Headers
        std::string line;
        std::getline(ifs, line);

        while(std::getline(ifs, line))
        {
            QStringList qList_Line = QString::fromStdString(line).split(",");
            
            if(qList_Line.size() < 5) {
                ErrorWindow* errorWindow = new ErrorWindow();
                errorWindow->setAttribute(Qt::WA_DeleteOnClose);
                errorWindow->setTitleText("File Error");
                errorWindow->setErrorText("Incorrect format in csv file. Rerun simulation and confirm the output");
                errorWindow->show();               
            }
            else
            {
                this->tsDataPoints.push_back(TsDataPoint{qList_Line.at(1).toDouble(), qList_Line.at(5).toDouble()}); 
            }
        }

        if(this->tsDataPoints.size() < 4)
        {
            ErrorWindow* errorWindow = new ErrorWindow();
            errorWindow->setAttribute(Qt::WA_DeleteOnClose);
            errorWindow->setTitleText("File Error");
            errorWindow->setErrorText("Incorrect format in csv file. Rerun simulation and confirm the output");
            errorWindow->show();  
        }
        else
        {
            this->pointGeneration();
        }
    }
}

TsDataPoints::~TsDataPoints() {}

std::vector<TsDataPoint> TsDataPoints::get_tsDataPoints()
{
    return this->tsDataPoints;
}

void TsDataPoints::pointGeneration()
{
    // Define the exact relationships when heat is added and subtracted
    double t1 = this->tsDataPoints.at(0).temperature;
    double t2 = this->tsDataPoints.at(1).temperature;
    double t3 = this->tsDataPoints.at(2).temperature;
    double t4 = this->tsDataPoints.at(3).temperature;

    double s1 = this->tsDataPoints.at(0).entropy;
    double s2 = this->tsDataPoints.at(1).entropy;
    double s3 = this->tsDataPoints.at(2).entropy;
    double s4 = this->tsDataPoints.at(3).entropy;

    // Find specific heats using s2 - s1 = cln(t2/t1)
    double c1 = (s3 - s2) / std::log(t3 / t2);
    double c2 = (s1 - s4) / std::log(t1 / t4);

    int index = 1;

    // Compression
    if(s2 != s1) // check if NOT isentropic
    {
        double c_compress = (s2 - s1) / std::log(t2 / t1); // Although there is a pressure or volume term. I am using approximations to decrease complexity.

        double step = (t2 - t1) / 30.0;

        for(double temp = t1 + step; temp < t2; temp += step)
        {
            // s = s_o + c ln (temp / t_o)
            this->tsDataPoints.insert(tsDataPoints.begin() + index, TsDataPoint{temp, s1 + c_compress*std::log(temp / t1)});
            index++;
        }
    }

    // Heat In
    double step = (t3 - t2) / 30.0;
    
    index++;

    for(double temp = t2 + step; temp < t3; temp += step)
    {
        // s = s_o + c ln (temp / t_o)
        this->tsDataPoints.insert(tsDataPoints.begin() + index, TsDataPoint{temp, s2 + c1*std::log(temp / t2)});
        index++;
    }

    index++;

    // Expansion
    if(s3 != s4) // check if NOT isentropic
    {
        double c_expan = (s4 - s3) / std::log(t4 / t3); // Although there is a pressure or volume term. I am using approximations to decrease complexity.

        double step = (t4 - t3) / 30.0;

        for(double temp = t3 + step; temp < t4; temp += step)
        {
        // s = s_o + c ln (temp / t_o)
        this->tsDataPoints.insert(tsDataPoints.begin() + index, TsDataPoint{temp, s3 + c_expan*std::log(temp / t3)});
        index++;
        }
    }

    // Heat out
    TsDataPoint lastPoint;
    lastPoint = tsDataPoints.at(tsDataPoints.size() - 1);
    this->tsDataPoints.pop_back();

    step = (t1 - t4) / 30.0;

    for(double temp = t4 + step; temp > t1; temp+=step)
    {
        this->tsDataPoints.push_back( TsDataPoint{temp, s4 + c2*std::log(temp / t4)});
    }
    this->tsDataPoints.push_back(lastPoint);
}

QMainWindow *TsDataPoints::graphTsDiagram()
{
    // 1. Create Series
    QLineSeries *series = new QLineSeries();
    
    // Initialize min/max variables to find the data range
    double minValX = std::numeric_limits<double>::max();
    double maxValX = std::numeric_limits<double>::lowest();
    double minValY = std::numeric_limits<double>::max();
    double maxValY = std::numeric_limits<double>::lowest();

    for(const auto& dataPoint : this->tsDataPoints)
    {
        series->append(dataPoint.entropy, dataPoint.temperature);

        // Find Min/Max for Scaling
        if(dataPoint.entropy < minValX) minValX = dataPoint.entropy;
        if(dataPoint.entropy > maxValX) maxValX = dataPoint.entropy;
        if(dataPoint.temperature < minValY) minValY = dataPoint.temperature;
        if(dataPoint.temperature > maxValY) maxValY = dataPoint.temperature;
    }
    
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ts Diagram");
    chart->legend()->hide();

    // 2. Define Axes with calculated ranges
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("entropy (kJ / kg * K)");
    
    // Set Range with 10% padding so points aren't on the edge
    double paddingX = (maxValX - minValX) * 0.01;
    axisX->setRange(minValX - paddingX, maxValX + paddingX); 
    
    axisX->applyNiceNumbers();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX); 

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Temperature (K)");
    
    // Set Range with 10% padding
    double paddingY = (maxValY - minValY) * 0.01;
    axisY->setRange(minValY - paddingY, maxValY + paddingY);

    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *diagram = new QMainWindow();
    diagram->setCentralWidget(chartView);
    diagram->setAttribute(Qt::WA_DeleteOnClose);
    diagram->resize(1080, 720);
    diagram->show();

    return diagram;
}