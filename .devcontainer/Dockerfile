FROM espressif/idf:release-v5.2

RUN apt update -y && apt install -y \
    sudo\
    make\
    git\
    build-essential\
    cmake \
    gdb \
    gdbserver \
    udev \
    usbutils

# used for on-board JTAG (i.e. not the USB-to-UART bridge)
RUN wget -O /etc/udev/rules.d/60-openocd.rules https://raw.githubusercontent.com/espressif/openocd-esp32/refs/heads/master/contrib/60-openocd.rules

ARG USER=user

RUN useradd -m $USER && echo "$USER:$USER" | chpasswd && adduser $USER sudo
RUN echo "$USER            ALL = (ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN adduser $USER dialout
RUN adduser $USER plugdev

# required for ESP32 built-in JTAG
RUN echo "export PATH=/opt/esp/tools/openocd-esp32/v0.12.0-esp32-20241016/openocd-esp32/bin/openocd:$PATH" >> /home/$USER/.bashrc
RUN echo "export OPENOCD_SCRIPTS=/opt/esp/tools/openocd-esp32/v0.12.0-esp32-20241016/openocd-esp32/share/openocd/scripts" >> /home/$USER/.bashrc
RUN echo "sudo /lib/systemd/systemd-udevd --daemon" >> /home/$USER/.bashrc

CMD /bin/bash