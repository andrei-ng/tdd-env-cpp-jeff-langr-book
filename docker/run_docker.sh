#!/usr/bin/env bash

# Check args
if [ "$#" -lt 1 ]; then
  echo "usage: ./run.sh IMAGE_NAME"
  return 1
fi

set -e

IMAGE_NAME=$1 && shift 1
NVIDIA_DOCKER_VERSION=$(dpkg -l | grep nvidia-docker | awk '{ print $3 }' | awk -F'[_.]' '{print $1}')

# Determine the appropriate version of the docker run command
if [ $NVIDIA_DOCKER_VERSION = "1" ]; then
    docker_run_cmd="nvidia-docker run --rm"
elif [ $NVIDIA_DOCKER_VERSION = "2" ]; then
  docker_run_cmd="docker run --runtime=nvidia -e NVIDIA_VISIBLE_DEVICES=0 --rm"
else
  echo "[Warning] nvidia-docker not installed, running docker without Nvidia hardware acceleration / OpenGL support"
  docker_run_cmd="docker run --rm"
fi

# Deterimine configured user for the docker image
docker_user=$(docker image inspect --format '{{.Config.User}}' $IMAGE_NAME)
if [ "$docker_user" = "" ]; then
    dHOME_FOLDER="/root"
else
    dHOME_FOLDER="/home/$docker_user"    
fi

SRC_CODE_DIR="$(pwd)/../book_src_code"

# Run the container with NVIDIA Graphics acceleration, shared network interface, shared hostname, shared X11
$(echo $docker_run_cmd) \
  --net=host \
  --ipc=host \
  --privileged \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  -v $HOME/.Xauthority:$dHOME_FOLDER/.Xauthority \
  -e XAUTHORITY=$dHOME_FOLDER/.Xauthority \
  -e DISPLAY=$DISPLAY \
  -v $HOME/.gitconfig:$dHOME_FOLDER/.gitconfig \
  -v $SRC_CODE_DIR:$dHOME_FOLDER/book_src_code \
  -v $HOME/SoftwareTools/Qt:/$dHOME_FOLDER/Qt \
  -v $HOME/.config/QtProject/:/$dHOME_FOLDER/.config/QtProject/ \
  -it $IMAGE_NAME "$@"