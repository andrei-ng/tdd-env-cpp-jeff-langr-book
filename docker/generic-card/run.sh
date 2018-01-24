#!/usr/bin/env bash

# Check args
if [ "$#" -lt 1 ]; then
  echo "usage: ./run.sh IMAGE_NAME"
  return 1
fi

set -e

IMAGE_NAME=$1 && shift 1

# Deterimine user of the docker image
docker_user=$(docker image inspect --format '{{.Config.User}}' $IMAGE_NAME)
if [ "$docker_user" = "" ]; then
    dHOME_FOLDER="/root"
else
    dHOME_FOLDER="/home/$docker_user"    
fi

SRC_CODE_DIR="$(pwd)/../../book_src_code"

# Run the container with shared X11, shared network interface
docker run --rm \
  --net=host \
  --ipc=host \
  --privileged \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  -v $HOME/.Xauthority:$dHOME_FOLDER/.Xauthority \
  -e XAUTHORITY=$dHOME_FOLDER/.Xauthority \
  -e DISPLAY=$DISPLAY \
  -v $HOME/.gitconfig:$home_folder/.gitconfig \
  -v $SRC_CODE_DIR:$dHOME_FOLDER/book_src_code \
  -it $IMAGE_NAME "$@"