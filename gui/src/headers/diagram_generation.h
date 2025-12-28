#pragma once
#include <vector>
#include <string>
#include <QMainWindow>

/**
 * @brief Struct to contain all the pv data points
 */
struct PvDataPoint
{
    double pressure, specific_volume;
};

/**
 * @brief Struct to contain all the Ts data points
 */
struct TsDataPoint
{
    double temperature, entropy;
};

class PvDataPoints
{
    private:
        // Define neccessary variables for PV graphs
        std::vector<PvDataPoint> pvDataPoints;

    public:

        /**
         * @brief Constructor: Reads a file and assigns pvDataPoints a 1D vector that contains the pv data points
         * @param fileName file name of the csv that contains the data
         */
        PvDataPoints(std::string fileName);

        /**
         * @brief Destructor
         */
        ~PvDataPoints();

        /**
         * @brief Point generations to make the lines of the graphs better
         */
        void pointGeneration();

        /**
         * @brief Getter for pvDataPoints
         * @return this->pvDataPoints
         */
        std::vector<PvDataPoint> get_pvDataPoints();

        /**
         * @brief Graphs pv Diagram
         * @return displays a window with the associated pv diagram
         */
        QMainWindow* graphPvDiagram();
        
};

class TsDataPoints
{
    private:
        // Define neccessary variables for Ts graphs
        std::vector<TsDataPoint> tsDataPoints;

    public:

        /**
         * @brief Constructor: Reads a file and assigns ts a 1D vector that contains the ts data points
         * @param fileName file name of the csv that contains the data
         */
        TsDataPoints(std::string fileName);

        /**
         * @brief Destructor
         */
        ~TsDataPoints();
        
        /**
         * @brief Getter for TsDataPoints
         * @return this->tsDataPoints
         */
        std::vector<TsDataPoint> get_tsDataPoints();

        /**
         * @brief Point generations to make the lines of the graphs better
         */
        void pointGeneration();

        /**
         * @brief Graphs Ts Diagram
         * @return displays a window with the associated ts diagram
         */
        QMainWindow* graphTsDiagram();
};