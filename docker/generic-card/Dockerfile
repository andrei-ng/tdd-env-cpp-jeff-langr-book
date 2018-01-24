FROM ubuntu:xenial

MAINTAINER Andrei Gherghescu <gandrein@gmail.com>

LABEL Description="Ubuntu 16.04 Docker Container with development tools for Jeff Langr's Modern C++ TDD book" Version="1.0"

# Arguments
ARG user=docker
ARG uid=1000
ARG shell=/bin/bash

# ------------------------------------------ Install required (&useful) packages --------------------------------------
RUN apt-get update && apt-get install -y \
 software-properties-common \
 lsb-release mesa-utils \
 x11-apps locales\
 gdb valgrind \
 build-essential cmake scons \
 git subversion \
 nano vim \
 gnome-terminal terminator \
 wget curl unzip \
 sudo htop ssh zsh screen tree \
 astyle clang-format \
 libcanberra-gtk* \
 && add-apt-repository ppa:nholthaus/gtest-runner -y \
 && apt-get update && apt-get install gtest-runner libqt5opengl5 libqt5xml5 -y \
 && sudo locale-gen en_US.UTF-8 \
 && rm -rf /var/lib/apt/lists/* \
 && apt-get clean

# Configure timezone and locale 
ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en  
ENV LC_ALL en_US.UTF-8

# ---------------------------------- User enviroment config  -----------------------------
# Crete and add user
RUN useradd -ms ${shell} ${user}
ENV USER=${user}

RUN export uid=${uid} gid=${uid}

RUN \
  mkdir -p /etc/sudoers.d && \
  echo "${user}:x:${uid}:${uid}:${user},,,:$HOME:${shell}" >> /etc/passwd && \
  echo "${user}:x:${uid}:" >> /etc/group && \
  echo "${user} ALL=(ALL) NOPASSWD: ALL" > "/etc/sudoers.d/${user}" && \
  chmod 0440 "/etc/sudoers.d/${user}"

# Switch to user
USER ${user}

# Install and configure OhMyZSH
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true \
 && git clone https://github.com/sindresorhus/pure $HOME/.oh-my-zsh/custom/pure \
 && ln -s $HOME/.oh-my-zsh/custom/pure/pure.zsh-theme $HOME/.oh-my-zsh/custom/ \
 && ln -s $HOME/.oh-my-zsh/custom/pure/async.zsh $HOME/.oh-my-zsh/custom/ \
 && sed -i -e 's/robbyrussell/refined/g' $HOME/.zshrc

# Copy Terminator Configuration file
# '$HOME' does not seem to work with the COPY directive
RUN mkdir -p $HOME/.config/terminator/
COPY configs/terminator_config /home/${user}/.config/terminator/config
COPY configs/bash_aliases /home/${user}/.bash_aliases
COPY entrypoint.sh /home/${user}/entrypoint.sh
RUN sudo chmod +x /home/${user}/entrypoint.sh \
 && sudo chown ${user}:${user} /home/${user}/entrypoint.sh \
  	/home/${user}/.config/terminator/config \
  	 /home/${user}/.bash_aliases

# ==================================== Copy & Make packages required by book examples ==================================== 
# Note that these packages are old compared with the current version, but in order to follow with the book examples
# it is easier to use these packages rather than to fix dependencies for newer versions
RUN mkdir -p $HOME/packages
COPY book_libs/*  /home/${user}/packages/

# Make user the owner of all copied files 
# Not ideal, since it may add a large docker layer, but so far no simple alternative
RUN sudo chown -R ${user}:${user} /home/${user}

# ------------------- GMock and Gtest (v1.6.0) ----------------------
# Configure Google Mock and Google Test
ENV GMOCK_HOME /home/${user}/packages/gmock-1.6.0
# Build GMock & GTest( which for older versions is stored within Gtest)
RUN cd $HOME/packages && unzip gmock-1.6.0.zip && \
	cd $GMOCK_HOME && mkdir mybuild && cd mybuild && cmake .. && make && \
	cd $GMOCK_HOME/gtest && mkdir mybuild && cd mybuild && cmake .. && make

# ------------------- CppUTest (v3.3) ----------------------
ENV CPPUTEST_HOME /home/${user}/packages/cpputest 
RUN cd $HOME/packages && mkdir cpputest && tar -xpzf CppUTest-v3.3.tar.gz -C cpputest && \
	cd $CPPUTEST_HOME && make && make -f Makefile_CppUTestExt

# ------------------- curl (v7.29) ----------------------
ENV CURL_HOME /home/${user}/packages/curl-7.29.0
RUN cd $HOME/packages && tar -xpzf curl-7.29.0.tar.gz && \
	cd $CURL_HOME && mkdir build && cd build && cmake .. && make 

# ------------------- jsoncpp (v0.5.0) ----------------------
ENV JSONCPP_HOME /home/${user}/packages/jsoncpp-src-0.5.0
# Build JSONCPP with scons (this is an old mechanism)
RUN cd $HOME/packages && tar -xpzf jsoncpp-src-0.5.0.tar.gz && \
    cd $JSONCPP_HOME && scons platform=linux-gcc
# Create a symbolic link to the generated library so CMAKE can locate it
RUN cd $JSONCPP_HOME/libs/ && ln -s linux-gcc-$(gcc -dumpversion)/libjson_linux-gcc-$(gcc -dumpversion)_libmt.a libjson_linux-gcc.a

# ------------------- rlog (v1.4) ----------------------
ENV RLOG_HOME /home/${user}/packages/rlog-1.4
RUN cd $HOME/packages && tar -xpzf rlog-1.4.tar.gz && \
	cd $RLOG_HOME && ./configure && make 

# ------------------- Boost (v1.53.0) ----------------------
ENV BOOST_ROOT /home/${user}/packages/boost_1_53_0
ENV BOOST_VERSION 1.53.0
RUN cd $HOME/packages && tar -xpzf boost_1_53_0.tar.gz && \
	cd $BOOST_ROOT && ./bootstrap.sh --with-libraries=filesystem,system && ./b2

# Create a mount point to bind host data to
VOLUME /extern

# Make SSH available
EXPOSE 22
# Expose Gazebo port
EXPOSE 11345

# This is required for sharing Xauthority
ENV QT_X11_NO_MITSHM=1

# Switch to user's HOME folder
WORKDIR /home/${user}

# Using the "exec" form for the Entrypoint command
ENTRYPOINT ["./entrypoint.sh", "terminator"]
#CMD ["-e", "/usr/bin/zsh"]