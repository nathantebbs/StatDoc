# StatDoc Programming Language

Hi! This project is currently in the early stages of development. Please see docs folder for more info :)

## Using StatDoc

```bash
git pull https://github.com/nathantebbs/StatDoc
```

Build The Executable

```
cd StatDoc && make
# Or to install statdoc to your /usr/bin/ folder
cd StatDoc && sudo make install
```

To make checking out the project for yourself a little easier I have included a Dockerfile so you can build and run the project in a containerized environment!

Make sure you have [Docker Desktop](https://www.docker.com/products/docker-desktop/) or [Docker](https://docs.docker.com/engine/install/) installed on your machine.

Once you have docker installed and have pulled the GitHub repository, we are now able to setup our StatDoc development environment.

First, start by building the docker image
```bash
docker build -t statdoc:latest .
```

Now, we can run a container from our docker image
```bash
docker run -it statdoc:latest bash
```

Since I am going to come back to this container for future builds, I like
to keep the container on my PC and just start and stop it when I want.
Consider adding the --rm flag if you are launching containers frequently!
