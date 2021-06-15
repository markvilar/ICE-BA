# -----------------------------------------------------------------------------
# ---- Bundle Adjustment ------------------------------------------------------
# -----------------------------------------------------------------------------

set(HEADERS_BUNDLE_ADJUSTMENT
    BundleAdjustment/GlobalBundleAdjustor.h
    BundleAdjustment/LocalBundleAdjustor.h)

set(SOURCES_BUNDLE_ADJUSTMENT
    BundleAdjustment/GlobalBundleAdjustor.cpp
    BundleAdjustment/GlobalBundleAdjustorDL.cpp
    BundleAdjustment/GlobalBundleAdjustorGN.cpp
    BundleAdjustment/GlobalBundleAdjustorIO.cpp
    BundleAdjustment/LocalBundleAdjustor.cpp
    BundleAdjustment/LocalBundleAdjustorDL.cpp
    BundleAdjustment/LocalBundleAdjustorGN.cpp
    BundleAdjustment/LocalBundleAdjustorIO.cpp)

# -----------------------------------------------------------------------------
# ---- Geometry ---------------------------------------------------------------
# -----------------------------------------------------------------------------

set(HEADERS_GEOMETRY
    Geometry/BoundingBox.h
    Geometry/Camera.h
    Geometry/CameraPrior.h
    Geometry/CameraTrajectory.h
    Geometry/Depth.h
    Geometry/IMU.h
    Geometry/Intrinsic.h
    Geometry/M-Estimator.h
    Geometry/Point.h
    Geometry/Rigid.h
    Geometry/Rotation.h
    Geometry/Similarity.h)

set(SOURCES_GEOMETRY
    Geometry/Camera.cpp
    Geometry/CameraPrior.cpp
    Geometry/Depth.cpp
    Geometry/IMU.cpp
    Geometry/Intrinsic.cpp)

# -----------------------------------------------------------------------------
# ---- Linear Algebra ---------------------------------------------------------
# -----------------------------------------------------------------------------

set(LINEAR_ALGEBRA_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/LinearAlgebra")

set(HEADERS_LINEAR_ALGEBRA
    LinearAlgebra/LinearSystem.h
    LinearAlgebra/Matrix2x2.h
    LinearAlgebra/Matrix2x3.h
    LinearAlgebra/Matrix2x4.h
    LinearAlgebra/Matrix2x6.h
    LinearAlgebra/Matrix2x7.h
    LinearAlgebra/Matrix2x8.h
    LinearAlgebra/Matrix3x3.h
    LinearAlgebra/Matrix3x4.h
    LinearAlgebra/Matrix3x6.h
    LinearAlgebra/Matrix3x7.h
    LinearAlgebra/Matrix3x8.h
    LinearAlgebra/Matrix4x4.h
    LinearAlgebra/Matrix6x6.h
    LinearAlgebra/Matrix6x7.h
    LinearAlgebra/Matrix8x8.h
    LinearAlgebra/Matrix9x9.h
    LinearAlgebra/MatrixMxN.h
    LinearAlgebra/MatrixNxN.h
    LinearAlgebra/Vector12.h
    LinearAlgebra/Vector2.h
    LinearAlgebra/Vector3.h
    LinearAlgebra/Vector4.h
    LinearAlgebra/Vector6.h
    LinearAlgebra/Vector7.h
    LinearAlgebra/Vector8.h
    LinearAlgebra/Vector9.h
    LinearAlgebra/VectorN.h)

# -----------------------------------------------------------------------------
# ---- Map --------------------------------------------------------------------
# -----------------------------------------------------------------------------

set(HEADERS_MAP
    Map/Feature.h
    Map/Frame.h
    Map/GlobalMap.h
    Map/LocalMap.h)

set(SOURCES_MAP
    Map/Feature.cpp
    Map/GlobalMap.cpp
    Map/LocalMap.cpp)

# -----------------------------------------------------------------------------
# ---- Utility ----------------------------------------------------------------
# -----------------------------------------------------------------------------

set(UTILITY_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Utility")

set(HEADERS_UTILITY
    Utility/AlignedMatrix.h
    Utility/AlignedVector.h
    Utility/Candidate.h
    Utility/Configurator.h
    Utility/FillMap.h
    Utility/MultiThread.h
    Utility/SIMD.h
    Utility/simd_sse_neon.h
    Utility/Timer.h
    Utility/Utility.h)

set(SOURCES_UTILITY
    Utility/Utility.cpp
    Utility/MultiThread.cpp)

# -----------------------------------------------------------------------------
# ---- ICE-BA Library ---------------------------------------------------------
# -----------------------------------------------------------------------------

set(IBA_INCLUDE_DIRS 
    ${PROJECT_SOURCE_DIR}/Backend/IBA
    ${PROJECT_SOURCE_DIR}/Backend/BundleAdjustment
    ${PROJECT_SOURCE_DIR}/Backend/Geometry
    ${PROJECT_SOURCE_DIR}/Backend/LinearAlgebra
    ${PROJECT_SOURCE_DIR}/Backend/Map
    ${PROJECT_SOURCE_DIR}/Backend/Utility)

set(HEADERS_IBA
    IBA/IBA.h
    IBA/IBA_config.h
    IBA/IBA_datatype.h
    IBA/IBA_internal.h
    IBA/Parameter.h
    IBA/stdafx.h
    ${HEADERS_BUNDLE_ADJUSTMENT}
    ${HEADERS_GEOMETRY}
    ${HEADERS_LINEAR_ALGEBRA}
    ${HEADERS_MAP}
    ${HEADERS_UTILITY})

set(SOURCES_IBA
    IBA/IBA.cpp
    IBA/Parameter.cpp
    IBA/stdafx.cpp
    ${SOURCES_BUNDLE_ADJUSTMENT}
    ${SOURCES_GEOMETRY}
    ${SOURCES_LINEAR_ALGEBRA}
    ${SOURCES_MAP}
    ${SOURCES_UTILITY})

add_library(IBA SHARED ${SOURCES_IBA})

target_include_directories(IBA PUBLIC
    ${IBA_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${EIGEN_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${GLOG_INCLUDE_DIRS})

target_link_libraries(IBA PUBLIC
    ${Boost_LIBRARIES}
    ${GLOG_LIBRARIES}
    ${X11_LIBRARIES}
    pthread)

# -----------------------------------------------------------------------------
# ---- Visualization ----------------------------------------------------------
# -----------------------------------------------------------------------------

if(CVD_FOUND)
    set(VISUALIZATION_INCLUDE_DIR 
        ${PROJECT_SOURCE_DIR}/Backend/Visualization)

    set(HEADERS_VISUALIZATION
        Visualization/Arcball.h
        Visualization/EventHandler.h
        Visualization/Frustrum.h
        Visualization/Keyboard.h
        Visualization/TextureGL.h
        Visualization/TextureGL.hpp
        Visualization/UtilityWM.h
        Visualization/Viewer.h
        Visualization/ViewerIBA.h)

    set(SOURCES_VISUALIZATION
        Visualization/Viewer.cpp
        Visualization/ViewerIBA.cpp
        Visualization/ViewerIBADraw.cpp
        Visualization/ViewerIBAIO.cpp)

    add_library(IBAVis SHARED ${SOURCES_VISUALIZATION})

    target_include_directories(IBAVis PUBLIC
        ${VISUALIZATION_INCLUDE_DIR}
        ${IBA_INCLUDE_DIRS}
        ${CVD_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${EIGEN_INCLUDE_DIR})

    target_link_libraries(IBAVis PUBLIC
        IBA
        ${Boost_LIBRARIES}
        ${CVD_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY}
        ${GLEW_LIBRARIES}
        ${X11_LIBRARIES}
        Xrandr
        pthread)

endif(CVD_FOUND)
