# BeavSat cFE Code
The code that will run on the cFE of MIT's BeavCube Satellite

## Setup

To setup cFS directly from the latest release:

    git clone https://github.com/nasa/cFE.git
    cd cFE
    git submodule init
    git submodule update

## Build and Run

The latest release include sample applications and an example build target that uses the pc-linux platform support package (should run on most Linux distributions).

To compile and run:

    . ./setvars
    cd build/cpu1
    make config
    make
    cd exe
    sudo ./core-linux.bin
