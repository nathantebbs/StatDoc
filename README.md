# StatDoc Programming Language

> [!WARNING]
> *Hi! This project is a personal project for learning and currently it is in the early stages of development. Please see docs folder for more info :)*

## Using StatDoc

### Installation

Pull the GitHub repo

```bash
$ git pull https://github.com/nathantebbs/StatDoc
```

Build The Executable

```bash
$ make 
$ sudo make install
```
> [!NOTE]
> *The Makefile for this project is stored in the src/ directory. Additionally, when using the uninstall target, this will
not remove build files.*

### Docker (recommended)

To make checking out the project for yourself a little easier I have included a Dockerfile so you can build and run the project in a containerized environment!

Make sure you have [Docker Desktop](https://www.docker.com/products/docker-desktop/) or [Docker](https://docs.docker.com/engine/install/) installed on your machine.

Once you have docker installed and have pulled the GitHub repository, we are now able to setup our StatDoc development environment.

First, start by building the docker image
```bash
docker build -t statdoc:latest .
```

Now, we can run a container from our docker image
```bash
docker run -it --rm statdoc:latest bash
```

You can now follow the same installation steps outlined above. Enjoy!

