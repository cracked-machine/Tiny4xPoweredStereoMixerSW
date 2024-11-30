### Cpp Driver for DAC7718 IC.

See [components/dac7718/docs/dac7718.pdf](components/dac7718/docs/dac7718.pdf) for details on the serial interface.

### ESP32 target 

```
export BUILDTARGET=1
. /opt/esp/idf/export.sh
idf.py set-target esp32s3
idf.py build
idf.py flash
idf.py monitor
```

### Unit tests for x86 host

```
export BUILDTARGET=0
cmake -B buildhost -S .
cmake --build buildhost
pushd buildhost && ctest && popd
```
