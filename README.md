# NVIDIA-Jetson-OpenCV-Tutorials

This repos contains the source files of Episodes 0 to 7 of the Youtube series "NVIDIA Jetson OpenCV Tutorials".

Tested on JetPack 3.2.1 on L4T 28.2 for Jetson TX1, with default OpenCV version 3.3.1.

## Test Episodes

Generate make files with cmake. On "build" folder run:

    cmake ..

Then make and run. Example on episode 7 (contours):

    make -C build/ && ./build/cv_contours 
