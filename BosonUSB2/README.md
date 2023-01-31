
# Code Sources
- https://github.com/FLIR/BosonUSB.git
- https://github.com/eva-tech/BosonLinuxSDK.git

This folder compiles Opencv and the Boson SDK using CMake. This has only been tested on ubuntu 20.04.


# Linux Directions
1. Run CMake
```
cmake .
```
2. Run Make
```
make
```
3. Open the USB port
```
sudo chmod a+rwx /dev/ttyACM0
```