if [ -d "./build" ];then
    rm -rf build
    echo "clean build dir"
fi

if [ -f "./run" ];then
    rm run
    echo "clean run exe"
fi
