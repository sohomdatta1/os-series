# Tinkeros

A playground that I want to use to experiment with low-level programming and learn some OS development basics.

## Prerequisites

- A text editor such as [VS Code](https://code.visualstudio.com/).
- [Docker](https://www.docker.com/) for creating our build-environment.
- [Qemu](https://www.qemu.org/) for emulating our operating system.
  - Remember to add Qemu to the path so that you can access it from your command-line. ([Windows instructions here](https://dev.to/whaleshark271/using-qemu-on-windows-10-home-edition-4062))

## Setup

Build an image for our build-environment:

- `docker build . -t tinkeros`

## Build

Enter build environment:

- Linux: `docker run --rm -it -v $(pwd):/root/env tinkeros bash -c "make buid-x86_64"`
- MacOS: `docker run --rm -it -v $(pwd):/root/env tinkeros bash -c "make buid-x86_64"`
- Windows (CMD): `docker run --rm -it -v "%cd%":/root/env tinkeros bash -c "make buid-x86_64"`
- Windows (PowerShell): `docker run --rm -it -v "${pwd}:/root/env" tinkeros bash -c "make buid-x86_64"`
- NOTE: If you are having trouble with an unshared drive, ensure your docker daemon has access to the drive you're development environment is in. For Docker Desktop, this is in "Settings > Shared Drives" or "Settings > Resources > File Sharing".

## Emulate

You can emulate your operating system using [Qemu](https://www.qemu.org/): (Don't forget to add qemu to your path!)

- `qemu-system-x86_64 -serial stdio -cdrom dist/x86_64/kernel.iso`
- NOTE: When building your operating system, if changes to your code fail to compile, ensure your QEMU emulator has been closed, as this will block writing to `kernel.iso`.

## Cleanup

Remove the build-evironment image:

- `docker rmi tinkeros -f`

## Credits

This respository is based on the source code for [this YouTube tutorial series](https://www.youtube.com/playlist?list=PLZQftyCk7_SeZRitx5MjBKzTtvk0pHMtp).

You can find the revision for a specific episode on [this page](https://github.com/davidcallanan/yt-os-series/tags).

You can find pre-built ISO files for this kernel at [this repository](https://github.com/davidcallanan/os-series-isos).

Considering supporting the work of codepulse via [this Patreon page](http://patreon.com/codepulse).
