## Purpose

Docker image with development tools required for running the code samples from _Modern C++ Programming with Test-Driven Development (Code Better, Sleep Better)_ by Jeff Langr.

For details about the tools (and configuration) required to run the book's examples source code, read _Chapter 1: Global Setup_.

The image is customized such that:
* the docker image is created with a non-root user (default user-name `docker`)
* [Oh My ZSH](http://ohmyz.sh/) is installed and configured for the non-root user
* docker containers are launched with [`terminator`](https://gnometerminator.blogspot.nl/p/introduction.html) as the default terminal emulator (as opposed to default `gnome-terminal`)
* bash completion for Docker image names and tags when launching the container by using the `./run_docker.sh` script
	* remember to source the [bash_docker_images_completion.sh](./docker/configs/bash_docker_images_completion.sh) file from the [docker/configs](./dokcer/configs) folder.

## Requirements

This docker image has been build and tested on a machine running Ubuntu 16.04 with `docker` version `17.09.0-ce`. 

If your machine has a NVIDIA Video card, to successfully run OpenGL dependent GUIs from the docker container you will need to install [`nvidia-docker`](https://github.com/NVIDIA/nvidia-docker/wiki/Installation-(version-1.0)) version `1.0`. 


### Building the image

The [Makefile](./docker/Makefile) contained in the repository allows you to create docker images for the target platform you are interested in NVIDIA/nonNVIDIA. In a terminal type `make` followed by a `<TAB>` to see the available auto-complete options. 
```
make <TAB>
```

If you wish to change the names given to the Docker images the recommended way is to give a new TAG to the image by using the 
```
docker tag SOURCE_IMAGE[:TAG] TARGET_IMAGE[:TAG]
```

command, after you have build it with the `make` instruction. 

You could also change the names in the `Makefile`. However, make sure you do not break the dependencies between the two images as the second image (for NVIDIA platform) depends on the first. 

#### The ENTRYPOINT `entrypoint.sh` script
For each image type, the bash script [entrypoint.sh](./docker/entrypoint.sh) will be copied at build time into the Docker image and will be ran as the default _entrypoint_ when the container is launched. 

The current entrypoint script is customized for the use case where the host's QT Creator folder is mounted into the container at `$HOME/Qt` folder of the `non-root` user. 

The script creates an alias for the QT Creator's executable so it can be launched from the container's terminal with `qtcreator` command.

### Running a container

In the terminal call the [./run_docker.sh](./docker/run_docker.sh) script from the [docker](./docker) folder with the default given name or the name. The script will perform some Docker environment variables setting and volume mounting and set other docker flags, e.g., remove the container upon exit (i.e., it is ran with the `--rm` flag).

```
./run_docker.sh IMAGE_NAME
```

The script checks for the existence and the version of `nvidia-docker` and calls `docker run` differently based on version. The container shares the X11 unix socket with the host and its network interface.

### Book source code

This repository already contains a copy of the [book's source code](https://pragprog.com/titles/lotdd/source_code) in the directory [book_src_code](./book_src_code). This is mounted in the Docker container for you. 

However, if you wish to download a more recent version of the source code, downlaod it from [sources](https://pragprog.com/titles/lotdd/source_code) to a folder of your choice and change the docker volume mount command in the `run_docker.sh` script to something like
```
    -v $HOME/Downloads/cpp_tdd_book_src_code:$dHOME_FOLDER/book_src_code \
```
to reflect your own source path.


#### When the builds fail ...

In my case, even with the setup of this docker image, none of the examples could be built. What solved it for me, for e.g. for the Chapter 2 samples, was to revert the linking order in the `CMakeLists.txt` and place the `gmock` and `gtest` libraries before the `pthread` library, i.e.,
```
set(sources 
   main.cpp 
   SoundexTest.cpp)
add_executable(test ${sources})

target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test pthread)

```

### Bash auto-completion for `./run_docker.sh`

When using `./run_docker.sh` in a bash shell to launch the container, source the [configs/bash_docker_images_completion.sh](./docker/configs/bash_docker_images_completion.sh) script. Now you should be able to get the names of the available docker images on your system whenever you type 
```
./run_docker.sh <TAB><TAB>
```