#!/bin/sh

# Modified by rissu

ACCOUNT="tiann"
BRANCH_TARGET="-b main"
GIT_COMMANDS="git clone https://github.com/$ACCOUNT/KernelSU $(echo $BRANCH_TARGET)"
cd ..

set -eux

GKI_ROOT=$(pwd)
echo "-- Kernel Tree: $GKI_ROOT"

# Detect if another KernelSU tree is exist, then delete it.
if test -d "$GKI_ROOT/KernelSU"; then
	rm -rR $GKI_ROOT/KernelSU;
fi

# Check driver path
if test -d "$GKI_ROOT/drivers"; then
     DRIVER_DIR="$GKI_ROOT/drivers"
else
     echo '! - "drivers/" directory is not found.'
     echo '! - You should modify this script by yourself.'
     exit 127
fi

# Detect another kernelsu symlink in drivers/ exist, if yes, then delete it. 
if test -d "$DRIVER_DIR/kernelsu"; then
	rm -rR $DRIVER_DIR/kernelsu;
elif test -f "$DRIVER_DIR/kernelsu"; then
	rm $DRIVER_DIR/kernelsu;
fi

test -d "$GKI_ROOT/KernelSU" || $GIT_COMMANDS
cd "$GKI_ROOT/KernelSU"
git stash
if [ "$(git status | grep -Po 'v\d+(\.\d+)*' | head -n1)" ]; then
     git checkout main
fi
git pull
if [ -z "${1-}" ]; then
    git checkout "$(git describe --abbrev=0 --tags)"
else
    git checkout "$1"
fi
cd "$GKI_ROOT"

echo "-- Linking kernelsu drivers to $DRIVER_DIR"

cd "$DRIVER_DIR"
if test -d "$GKI_ROOT/drivers"; then
     ln -sf "../KernelSU/kernel" "kernelsu"
fi
cd "$GKI_ROOT"
