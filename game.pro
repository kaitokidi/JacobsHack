TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
        utils.cpp \
        Resources.cpp \
        Game.cpp \
        Scene.cpp \
        SceneMenu.cpp \
        SceneRace.cpp \
        Background.cpp \
        GUI/Button.cpp \
        GUI/Container.cpp \
        GUI/Frame.cpp \
        GUI/ImgButton.cpp \
        GUI/ImgTextButton.cpp \
        GUI/Label.cpp \
        GUI/Layout.cpp \
        GUI/TextButton.cpp \
        GUI/VLayout.cpp \
        GUI/HLayout.cpp \
        GUI/Widget.cpp \
        SoundManager.cpp \
    Player.cpp \
    Layer.cpp

HEADERS += utils.hpp \
        Resources.hpp \
        Game.hpp \
        Scene.hpp \
        SceneMenu.hpp \
        SceneRace.hpp \
        Background.hpp \
        GUI/Button.hpp \
        GUI/Container.hpp \
        GUI/ImgButton.hpp \
        GUI/ImgTextButton.hpp \
        GUI/Label.hpp \
        GUI/Layout.hpp \
        GUI/TextButton.hpp \
        GUI/VLayout.hpp \
        GUI/HLayout.hpp \
        GUI/Widget.hpp \
        GUI/Frame.hpp \
        SoundManager.hpp \
    Player.hpp \
    Layer.hpp
