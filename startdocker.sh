#!/bin/bash

docker run -e DISPLAY=host.docker.internal:0 --rm -it -v $(pwd):/source burgerspace  "$@"
