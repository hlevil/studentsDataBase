#!/bin/bash
# Скрипт для локальной установки зависимостей

echo "Installing required packages..."
sudo apt-get update
sudo apt-get install -y build-essential libgtest-dev cmake googletest

echo "Building GoogleTest..."
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib

echo "Setup completed successfully!"
