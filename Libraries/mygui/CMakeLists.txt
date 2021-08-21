add_library(mygui INTERFACE)

file(GLOB KLIB_INCLUDES_MYGUI
    "$ENV{KLIB_INCLUDE_DIR}/mygui/*.h"
)

target_include_directories(mygui INTERFACE ${KLIB_INCLUDES_MYGUI})
target_link_libraries(mygui INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/MyGUIEngine_x64.lib")