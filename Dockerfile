FROM gcc:4.9

COPY . /DockerWorld

WORKDIR /DockerWorld/

RUN gcc -o DockerWorld dockerworld.c

CMD [“./DockerWorld”]

