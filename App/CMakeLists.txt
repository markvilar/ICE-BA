cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# -----------------------------------------------------------------------------
# ---- Application build options ----------------------------------------------
# -----------------------------------------------------------------------------

option(BUILD_EUROC_APP "Build Euroc test application." OFF)
option(BUILD_BACKEND_APP "Build backend test application." ON)

# -----------------------------------------------------------------------------
# ---- Application dependencies -----------------------------------------------
# -----------------------------------------------------------------------------

find_package(Glog REQUIRED)
find_package(GFlags REQUIRED)

# -----------------------------------------------------------------------------
# ---- Frontend + backend with EuRoC dataset ----------------------------------
# -----------------------------------------------------------------------------

if(BUILD_EUROC_APP)
    add_executable(EurocTest EurocTest.cpp)

    target_link_libraries(EurocTest PRIVATE 
        IBA
        glog)

    if(CVD_FOUND)
        target_link_libraries(EurocTest IBAVis)
    endif(CVD_FOUND)
endif()

# -----------------------------------------------------------------------------
# ---- Backend-only with .dat file --------------------------------------------
# -----------------------------------------------------------------------------

if(BUILD_BACKEND_APP)
    add_executable(Backend RunBackend.cpp)

    target_include_directories(Backend PRIVATE
        ${IBA_INCLUDE_DIRS}
        ${EIGEN_INCLUDE_DIR}
        ${GLOG_INCLUDE_DIR}
        ${GFLAGS_INCLUDE_DIR})


    target_link_libraries(Backend PRIVATE
        IBA
        glog
        ${GFLAGS_LIBRARIES})

    if(CVD_FOUND)
        target_include_directories(Backend PUBLIC 
            ${VISUALIZATION_INCLUDE_DIR})
        target_link_libraries(Backend IBAVis)
    endif(CVD_FOUND)
endif()
