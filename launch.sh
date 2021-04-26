#!/bin/bash

docker run -v $(pwd):/root/env tinkeros bash -c "make clean && make build-x86_64"
qemu-system-x86_64 -serial stdio -cdrom dist/x86_64/kernel.iso
