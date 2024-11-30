FROM espressif/idf:release-v5.2

RUN apt update -y && apt install -y \
    sudo\
    make\
    git\
    build-essential\
    cmake \
    gdb \
    gdbserver \
    python3-pip \
    python3-pytest

ARG USER=user

RUN useradd -m $USER && echo "$USER:$USER" | chpasswd && adduser $USER sudo
RUN echo "$USER            ALL = (ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN adduser $USER dialout

# RUN echo ". /opt/esp/idf/export.sh" >> /home/$USER/.bashrc
CMD /bin/bash