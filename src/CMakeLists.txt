cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SFML_template)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp enumList.h Font.cpp Font.h States.cpp States.h Screen.cpp Screen.h
        Position.cpp Position.h Lists.cpp Lists.h MouseEvents.cpp MouseEvents.h
        RunProgram.cpp RunProgram.h GreenCircle/GreenCircleClass.cpp GreenCircle/GreenCircleClass.h

        BouncingBall

        Pong
        Pong/ball.cpp Pong/ball.h Pong/paddle.cpp Pong/paddle.h

        TopHatGuy
        TopHatGuy/TopahatGuy.cpp TopHatGuy/TopahatGuy.h

        PokerAnalysis
        PokerAnalysis/PokerAnalysis.cpp PokerAnalysis/PokerAnalysis.h
        PokerAnalysis/Card.cpp PokerAnalysis/Card.h PokerAnalysis/CardHand_Cards.cpp PokerAnalysis/CardHand_Cards.h PokerAnalysis/suits_struct.h PokerAnalysis/ranks_struct.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h
        PokerAnalysis/deck_class.cpp PokerAnalysis/deck_class.h PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHand.h PokerAnalysis/card_class.cpp
        PokerAnalysis/card_class.h PokerAnalysis/calculateOutput.h PokerAnalysis/calculateOutput.cpp

        BouncingBall/BouncingBall.cpp BouncingBall/BouncingBall.h Pong/Pong.cpp Pong/Pong.h

        TRexRunner/main.cpp TRexRunner/Game.h TRexRunner/Game.cpp
        TRexRunner/StartScreen.cpp TRexRunner/StartScreen.h
        TRexRunner/Score.cpp TRexRunner/Score.h
        TRexRunner/GameOver.cpp TRexRunner/GameOver.h TRexRunner/Ground.cpp TRexRunner/Ground.h
        TRexRunner/Trees.cpp TRexRunner/Trees.h TRexRunner/Dinosaur.cpp TRexRunner/Dinosaur.h TRexRunner/TRexRunner.cpp TRexRunner/TRexRunner.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} Font.cpp Font.h States.cpp States.h Screen.cpp Screen.h
            Position.cpp Position.h Lists.cpp Lists.h MouseEvents.cpp MouseEvents.h
            RunProgram.cpp RunProgram.h GreenCircle/GreenCircleClass.cpp GreenCircle/GreenCircleClass.h

            BouncingBall

            Pong
            Pong/ball.cpp Pong/ball.h Pong/paddle.cpp Pong/paddle.h

            TopHatGuy
            TopHatGuy/TopahatGuy.cpp TopHatGuy/TopahatGuy.h

            PokerAnalysis
            PokerAnalysis/PokerAnalysis.cpp PokerAnalysis/PokerAnalysis.h
            PokerAnalysis/Card.cpp PokerAnalysis/Card.h PokerAnalysis/CardHand_Cards.cpp PokerAnalysis/CardHand_Cards.h PokerAnalysis/suits_struct.h PokerAnalysis/ranks_struct.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h
            PokerAnalysis/deck_class.cpp PokerAnalysis/deck_class.h PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHand.h PokerAnalysis/card_class.cpp
            PokerAnalysis/card_class.h PokerAnalysis/calculateOutput.h PokerAnalysis/calculateOutput.cpp

            BouncingBall/BouncingBall.cpp BouncingBall/BouncingBall.h Pong/Pong.cpp Pong/Pong.h

            TRexRunner/main.cpp TRexRunner/Game.h TRexRunner/Game.cpp
            TRexRunner/StartScreen.cpp TRexRunner/StartScreen.h
            TRexRunner/Score.cpp TRexRunner/Score.h
            TRexRunner/GameOver.cpp TRexRunner/GameOver.h TRexRunner/Ground.cpp TRexRunner/Ground.h
            TRexRunner/Trees.cpp TRexRunner/Trees.h TRexRunner/Dinosaur.cpp TRexRunner/Dinosaur.h TRexRunner/TRexRunner.cpp TRexRunner/TRexRunner.h)
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES} Font.cpp Font.h States.cpp States.h Screen.cpp Screen.h
            Position.cpp Position.h Lists.cpp Lists.h MouseEvents.cpp MouseEvents.h
            RunProgram.cpp RunProgram.h GreenCircle/GreenCircleClass.cpp GreenCircle/GreenCircleClass.h

            BouncingBall

            Pong
            Pong/ball.cpp Pong/ball.h Pong/paddle.cpp Pong/paddle.h

            TopHatGuy
            TopHatGuy/TopahatGuy.cpp TopHatGuy/TopahatGuy.h

            PokerAnalysis
            PokerAnalysis/PokerAnalysis.cpp PokerAnalysis/PokerAnalysis.h
            PokerAnalysis/Card.cpp PokerAnalysis/Card.h PokerAnalysis/CardHand_Cards.cpp PokerAnalysis/CardHand_Cards.h PokerAnalysis/suits_struct.h PokerAnalysis/ranks_struct.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h
            PokerAnalysis/deck_class.cpp PokerAnalysis/deck_class.h PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHand.h PokerAnalysis/card_class.cpp
            PokerAnalysis/card_class.h PokerAnalysis/calculateOutput.h PokerAnalysis/calculateOutput.cpp

            BouncingBall/BouncingBall.cpp BouncingBall/BouncingBall.h Pong/Pong.cpp Pong/Pong.h

            TRexRunner/main.cpp TRexRunner/Game.h TRexRunner/Game.cpp
            TRexRunner/StartScreen.cpp TRexRunner/StartScreen.h
            TRexRunner/Score.cpp TRexRunner/Score.h
            TRexRunner/GameOver.cpp TRexRunner/GameOver.h TRexRunner/Ground.cpp TRexRunner/Ground.h
            TRexRunner/Trees.cpp TRexRunner/Trees.h TRexRunner/Dinosaur.cpp TRexRunner/Dinosaur.h TRexRunner/TRexRunner.cpp TRexRunner/TRexRunner.h)
endif ()

set(SFML_ROOT "C:/SFML-2.5.1")
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()