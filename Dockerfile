FROM amd64/debian:stretch

RUN apt-get update && apt-get install -y \
    build-essential \
    libsdl-image1.2-dev \
    libsdl-mixer1.2-dev \
    pkg-config \
    wget &&\
    mkdir -p /usr/local/src &&\
    cd /usr/local/src &&\
    wget https://perso.b2b2c.ca/~sarrazip/dev/flatzebra-0.1.6.tar.gz && tar zxf flatzebra-0.1.6.tar.gz && \
    rm flatzebra-0.1.6.tar.gz && \
    cd /usr/local/src/flatzebra-0.1.6/ &&\
    ./configure && make && make install &&\
    ldconfig
