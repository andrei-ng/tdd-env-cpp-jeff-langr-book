#!/usr/bin/env bash

# Check args
if [ "$#" -ne 1 ]; then
  echo "usage: ./build.sh IMAGE_NAME"
  exit 1
fi

# Set custom arguments
dUSER=docker
dSHELL=/usr/bin/zsh

# Copy custom config files
cp -r ../configs configs
# Copy book libraries
cp -r ../book_libs/ book_libs

# Build the docker image
docker build \
  --build-arg user=$dUSER\
  --build-arg uid=$UID\
  --build-arg shell=$dSHELL\
  -t $1 .

# Remove configs folder
rm -rf configs
# Remoe book libraries
rm -rf book_libs
