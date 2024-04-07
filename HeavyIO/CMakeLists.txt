project(HeavyIO)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} sourceFiles)

message(-----------${sourceFiles})

add_executable(${PROJECT_NAME} ${sourceFiles})