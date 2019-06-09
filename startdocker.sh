#!/bin/bash

pulseaudio --load=module-native-protocol-tcp --exit-idle-time=-1 --daemon
docker run -e PULSE_SERVER=docker.for.mac.localhost -e DISPLAY=host.docker.internal:0 --rm -it -v $(pwd):/source -v ~/.config/pulse:/home/pulseaudio/.config/pulse burgerspace "$@"
