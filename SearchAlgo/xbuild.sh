if [ -d "./build" ];then # -d 判断目录是否存在
    rm -rf build
    echo "clean build"
fi
    mkdir build
    cd build
    cmake ..
    make -j8
    echo "make over"
