# Cmakeの最低限のバージョン指定
cmake_minimum_required(VERSION 3.1.1)

# make
set(CMAKE_VERBOSE_MAKEFILE 1)

# プロジェクト名
PROJECT( dragonflylib )

# コンパイルオプション
add_definitions("-std=c++11 -o2 ")

# ライブラリの検索
find_package( Boost)
find_package( OpenCV REQUIRED )
find_package( PkgConfig REQUIRED)

# includeファイルの指定例(mac)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(/usr/local/include/eigen3)

# 共有ライブラリの作成を指示．
add_library( dragonflylib SHARED
 logging/logging.cpp
)

# ライブラリの指定
target_link_libraries( dragonflylib ${Boost_LIBRARY} m )
target_link_libraries( dragonflylib ${OpenCV_LIBS})
target_link_libraries( dragonflylib ${Eigen_LIBS})