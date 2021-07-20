set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 3.1)
project(SpaceInvadersJH)


# ustawienia SFML-a dla Linuksa/MacOS i Windows - proszę zostawić obie konfiguracje,
# CMake automatycznie użyje właściwej
if (UNIX)
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # pierwszy wpis powinien poprawnie skonfigurować SFML-a dla wszystkich
    # Debianopodobnych dystrybucji
    list(APPEND CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")

endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set(SFML_STATIC_LIBRARIES TRUE )

    # można zmienić katalog na właściwy
    set(SFML_DIR "C:/Users/macie/Desktop/SFML-2.5.1/lib/cmake/SFML")
endif(WIN32)


# to polecenie się wywali, jeśli CMake nie znajdzie SFML-a w jednym ze wskazanych
# wcześniej katalogów - nie ma potrzeby robienia potem if-a dla target_link_libraries
find_package(SFML 2 COMPONENTS graphics audio window system REQUIRED)

add_executable(SpaceInvadersJH main.cpp SpaceInvadersBoard.cpp SpaceShip.cpp SFMLView.cpp MainMenu.cpp GameOver.cpp)
target_link_libraries(SpaceInvadersJH sfml-graphics sfml-audio sfml-window sfml-system)

# W kodzie w dyrektywach #include należy używać konwencji #include <SFML/...>