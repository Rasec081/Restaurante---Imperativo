cmake_minimum_required(VERSION 3.28.3)
project(Imperativo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Imperativo
        client/client_app.cpp
        client/client_logic.cpp
        client/client_ui.cpp
        server/order_manager.cpp
        server/product_manager.cpp
        server/config.cpp
        network_client.cpp
        network_server.cpp
)