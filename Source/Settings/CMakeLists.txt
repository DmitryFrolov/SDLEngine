set(SETTINGS engine_settings)

set(HEADERS
    public/EngineSettings.h
    public/WindowSettings.h
    )

set(SOURCES
    private/EngineSettings.cpp
    private/WindowSettings.cpp
    )

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${SETTINGS} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${SETTINGS}
    PUBLIC public
    )

target_link_libraries(${SETTINGS}
    PUBLIC nlohmann_json::nlohmann_json
    )