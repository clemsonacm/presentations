FROM fedora

RUN dnf install -y gcc-c++ make gdb ctags vim
COPY *.cc Makefile /examples/
WORKDIR /examples/
