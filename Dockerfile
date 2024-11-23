FROM gcc:4.9
LABEL maintainer="Pierce Le <hale0087@uni.sydney.edu.au>"
COPY . /DockerWorld

WORKDIR /DockerWorld/

RUN gcc -o DockerWorld dockerworld.c

CMD [“./DockerWorld”]

