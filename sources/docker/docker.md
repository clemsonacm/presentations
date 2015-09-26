# Dockerize All the Things!


### An introduction to Docker brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &

[freenode #clemsonacm](irc.freenode.com)!

### Speakers:

Robert Underwood - ACM Vice President



## Coming Up

- What is a Docker, and why do I care?
   - Compare to Native and VM
   - Common Misconceptions
- How can I use a Docker container?
- How can I dockerize all the things?



# What is a Docker, and why do I care?



## What is Docker?

- Docker is a set of tools that make it easy to build, ship, and run
   applications
   - Commands to create containers and images
   - Standard to share those images with others
   - A thin runtime layer using `namespaces` and `cgroups`



## What is a Docker images?

- A set of layers that tell the history of an environment
- The state of the current environment
- An easy to use template to build new environments



## What is a Docker Container?

- A definition of an environment for which to run software
- Meant to be throw away
- Like a VM without the bloat
- Like a chroot with process isolation
- Like a BSD Jail without the BSD



## Why do I care?

- Much better scalability than VMs
- Faster deployment than VMs
- Better isolation and security than a chroot
- For some applications better performances



## Common Misconceptions

- Docker is _not_ a vm.
   - The kernel is shared but `namespaced`
   - No emulation of hardware
   - Uses `cgroups` to control resources
- Not the same as native
   - `AUFS` - `COW` Filesystem
   - `Docker NAT Bridge`



# How do I use Docker?



## Gotchas

- Older versions are fairly unsupported
- Requires docker service to be running
- Requires `root` access to access daemon
- `docker` group has password-less root access
- `Docker` and `selinux` don't always play nice.



## Life Cycle of a container

- Create a new container -- `docker run`
- Stop a running container -- `docker stop`
- Start a stopped container -- `docker start`
- Restart a container -- `docker restart`
- Delete container -- `docker rm`



## Run a container

```bash
docker run <options> <container> <arguments>
docker run -it ubuntu /bin/bash
docker run --name nginx -d -p 8080:80  \
   -v /docker/nginx.conf:/etc/nginx/nginx.conf:ro nginx
```

- `-it` -- keep `STDIN` open and allocate `pesdo-tty`
- `-v` -- mount a volume
- `-p` -- map a port
- `--net=host` -- host level networking 
- `--privileged` -- removes security features
- Default entry point is `/bin/sh`



## Manage Images

- Download a new image -- `docker pull`
- Upload an image -- `docker push`
- Build an image -- `docker build`
- Delete an image -- `docker rmi`



## Get information

- List containers -- `docker ps`
- List images -- `docker images`
- Port mappings -- `docker port`
- Detailed information -- `docker inspect`



## Administrative tasks

- Get a prompt -- `docker attach` or `nsenter`
- Run a command -- `docker exec`
- See the output -- `docker logs`
- Get usage stats -- `docker stats`



# How can I dockerize all the things?



## Committing images

- Run a new image
- Make your changes
- Commit your changes -- `docker commit`
- Tag the result -- `docker tag`



## Writing a Dockerfile

- Describes how container is to be built
- Each command `=` an image layer
- Only changed layers are built
- Similar commands to the command line



## Example Dockerfile

```dockerfile
## Development Tools
FROM centos:6.6
MAINTAINER "Robert Underwood" <email@example.com>
RUN yum install -y vim git python && yum update -y
ENV EDITOR=vim
ADD ["dotfiles/", "/root"]
EXPOSE 443/tcp 1094/udp
```



## Current Gotchas

- Builds are unpriviliged 
- Builds will fail if there is a prompt
- Init systems tend not to play nice
- Some files are based on the host
- No manpages inside by default



## Summary

- Docker is a new way to package applications
- It makes it easy to ensure the compatibility
- Docker is not a VM, jail, or chroot
- It provides serious advantages 
   - some disadvantages too



## Further Resources

- [Docker Docs]()
- [Docker Hub][]
- [Digital Ocean Tutorial][]
- [IBM Benchmarks][]
- [Why You Don't Need sshd][]



## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)

[Digital Ocean Tutorial]: https://www.digitalocean.com/community/tutorials/the-docker-ecosystem-an-introduction-to-common-components "Great Tutorial Series"
[Docker Hub]: https://registry.hub.docker.com/ "Base image repo"
[Docker Docs]:  https://docs.docker.com/ "Project Documentation"
[IBM Benchmarks]: http://domino.research.ibm.com/library/cyberdig.nsf/papers/0929052195DD819C85257D2300681E7B/$File/rc25482.pdf "very detailed benchmarks"
[Why You Don't Need sshd]: https://blog.docker.com/2014/06/why-you-dont-need-to-run-sshd-in-docker/ "tools to administrate docker containers"
