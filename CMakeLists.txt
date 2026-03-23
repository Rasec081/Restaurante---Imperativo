cmake_minimum_required(VERSION 3.28.3)
project(Imperativo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Imperativo main.cpp
        server/products_ui.cpp
        server/app.cpp
        server/order_manager.h
        shared/models.h
        server/order_manager.cpp
        server/product_manager.cpp
        server/orders_ui.cpp
        server/orders_ui.h
        server/table_numbers_ui.cpp
        server/table_numbers_ui.h
)
