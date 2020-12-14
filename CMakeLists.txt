PROJECT(rpc)
CMAKE_MINIMUM_REQUIRED(VERSION 3.17.3)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

include(FetchContent)

FetchContent_Declare(api
        GIT_REPOSITORY git@github.com:FunctorK/apf-api.git
        GIT_TAG caf83e903070ea298e8fd3961d47b2f8dbc58c9e
        USES_TERMINAL_DOWNLOAD YES
        USES_TERMINAL_UPDATE YES
        )

FetchContent_MakeAvailable(api)

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main api)
