cmake_minimum_required(VERSION 3.28.3)
project(Imperativo)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/server
        ${PROJECT_SOURCE_DIR}/client
        ${PROJECT_SOURCE_DIR}/shared
)

# ======================
# SERVER
# ======================
add_executable(server_app
        network_server.cpp
        server/order_manager.cpp
)

target_link_libraries(server_app nlohmann_json::nlohmann_json)

# ======================
# CLIENT
# ======================
add_executable(client_app
        client/client_app.cpp
        client/client_ui.cpp
        client/client_logic.cpp
        network_client.cpp
)

target_link_libraries(client_app nlohmann_json::nlohmann_json)