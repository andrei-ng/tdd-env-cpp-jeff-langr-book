## Purpose

Image with development tools required for running the code samples from _Modern C++ Programming with Test-Driven Development (Code Better, Sleep Better)_ by Jeff Langr.

For details about the tools (and configuration) required to run the book's examples source code, read _Chapter 1: Global Setup_.

The image is customized such that 
* the docker image is created with a non-root user (defaul user-name `docker`)
* [Oh My ZSH](http://ohmyz.sh/) is installed and configured for the non-root user
* docker containers are launched with [`terminator`](https://gnometerminator.blogspot.nl/p/introduction.html) as the default application (`gnome-terminal` could have been used as well)
* bash complementation for Docker image names; when using <TAB> in combination with `./run.sh` in a terminal running `bash`
	* remember to source the [bash_custom_completion.sh](./config_files/bash_custom_completion.sh) file from the [config_files](./config_files) folder


## Requirements

This docker image has been build and tested on a machine running Ubuntu 16.04 with the following packages installed
* `docker` version `17.09.0-ce`
* [`nvidia-docker`](https://github.com/NVIDIA/nvidia-docker/wiki/Installation-(version-1.0)) version `1.0`

### Building the image

Run [./build.sh](./build.sh). This will create the image with the name given as first argument.

```
./build.sh IMAGE_NAME
```

### Running a container

Run [./run.sh](./run.sh) with the chosen name from the step above. This will run and remove the docker image upon exit (i.e., it is ran with the `--rm` flag).

```
./run.sh IMAGE_NAME
```

The script checks for the version of `nvidia-docker` and calls `docker run` differently based on version. The container shares the X11 unix socket with the host and its network interface.

### Book source code

Download the book's [source code](https://pragprog.com/titles/lotdd/source_code) to a folder of your choice and change the docker volume mount command below from the `run.sh` script
```
    -v $HOME/Downloads/cpp_tdd_book_src_code:$home_folder/book_src_code \
```
to reflect your own location.