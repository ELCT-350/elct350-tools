add_executable(main "src/main.cpp")

target_link_libraries(main htmlplotter)
target_link_libraries(main sciplot::sciplot)
target_link_libraries(main Eigen3::Eigen)
