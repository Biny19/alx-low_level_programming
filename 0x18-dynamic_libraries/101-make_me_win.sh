#!/bin/bash
wget -O /tmp https://github.com/Biny19/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libmask.so
export LD_PRELOAD=/tmp/lottery.so
