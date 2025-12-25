# GUI DIRECTORY 

The following document contains the layout of the gui directory

## gui/graphics

This directory contains the images required by this GUI

1. **brayton_cycle.png** -> This file contains the brayton cycle image
2. **diesel_cycle.png** -> This file contains the diesel cycle image
3. **otto_cycle.png** -> This file contains the otto cycle image

## gui/src

This directory contains 2 directories: gui/src/cpp_files and gui/src/headers.

The directory, cpp_files contains the following cpp files: 

1. **brayton_inputs.cpp** -> Contains the logic for the brayton inputs
2. **diesel_inputs.cpp** -> Contains the logic for the diesel inputs
3. **error_window.cpp** -> Contains the logic for the error window
4. **help_window.cpp** -> Contains the logic for the help window
5. **main_window.cpp** -> Contains the logic for the main window
6. **otto_inputs.cpp** -> Contains the logic for the otto inputs
7. **performance.cpp** -> Contains the logic for the performance window
8. **selection.cpp** -> Contains the logic for the selection
9. **states_window.cpp** -> Contains the logic for the states window

The directory, headers contains the following h files: 

1. **brayton_inputs.h** -> Outlines the brayton_inputs.cpp file
2. **diesel_inputs.h** -> Outlines the diesel_inputs.cpp file
3. **error_window.h** -> Outlines the error_window.cpp file
4. **help_window.h** -> Outlines the help_window.cpp file
5. **main_window.h** -> Outlines the main_window.cpp file
6. **otto_inputs.h** -> Outlines the otto_inputs.cpp file 
7. **performance.h** -> Outlines the performance.cpp file
8. **selection.h** -> Outlines the selection.cpp file
9. **states_window.h** -> Outlines the states_window.cpp file


## gui/ui 

This directory contains all the ui files created by qtdesigner. AUTOUIC is used to create the associated header files.

1. **brayton_inputs.ui** -> The xml-formated file that contains the design for the brayton inputs window.
2. **diesel_inputs.ui** -> The xml-formated file that contains the design for the diesel inputs window.
3. **error_window.ui** -> The xml-formated file that contains the design for the error window.
4. **help_window.ui** -> The xml-formated file that contains the design for the help window.
5. **main_window.ui** -> The xml-formated file that contains the design for the main window.
6. **otto_inputs.ui** -> The xml-formated file that contains the design for the otto inputs window.
7. **performance_window.ui** -> The xml-formated file that contains the design for performance window.
8. **selector_window.ui** -> The xml-formated file that contains the design for selector window.
9. **states_window.ui** -> The xml-formated file that contains the design for the states window.