FROM debian:bullseye-slim
LABEL Description="StatDoc Build Environment"

WORKDIR /code

RUN apt-get update && apt-get -y --no-install-recommends install \
	git \
	vim \
	make \
	curl \
	build-essential \
	sudo

COPY ./src ./src
COPY ./Makefile ./Makefile
COPY ./googletest ./googletest
