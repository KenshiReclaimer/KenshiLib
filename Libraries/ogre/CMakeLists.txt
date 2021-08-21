


add_library(ogre INTERFACE)

file(GLOB KLIB_INCLUDES_OGRE
    "$ENV{KLIB_INCLUDE_DIR}/ogre/*.h"
)
source_group("Ogre" FILES ${KLIB_INCLUDES_OGRE})
target_include_directories(ogre INTERFACE ${KLIB_INCLUDES_OGRE})
target_link_libraries(ogre INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/OgreMain_x64.lib")