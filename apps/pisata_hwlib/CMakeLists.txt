cmake_minimum_required(Version 2.6.4)
project(CFE_PISATA_HWLIB C)

include_directories(fsw/public_inc)

# The shared OSAL and cFE include directories should always be used
# Note that this intentionally does NOT include PSP-specific includes
include_directories(${CFECORE_SOURCE_DIR}/src/inc)
include_directories(${CFEPSP_SOURCE_DIR}/fsw/inc)
include_directories(/opt/vc/include)
#create the app module
add_cfe_app(pisata_hwlib ${LIB_SRC_FILES})
target_link_libraries(pisata_hwlib wiringPi)
