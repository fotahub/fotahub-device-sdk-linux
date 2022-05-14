# FotaHub&reg; Embedded Device SDK for Linux&reg; and Raspberry Pi
The FotaHub&reg; Device SDK for Linux&reg; and Raspberry Pi enables developers to create firmware for Linxu&reg; or Raspberry Pi-based IoT devices that can be updated through [FotaHub](http://fotahub.com). It provides an C99-based FotaHub client library along with a set of examples illustrating how the latter can be used and integrated in real applications.

# Supported targets

The FotaHub® Device SDK for Linux® and Raspberry Pi can be used on:
* Single board computers like Raspberry Pi and others
* Linux-based edge IoT devices
* Linux desktop computers (for testing and evaluation purposes)

> &#x1F6C8; You can test/evaluate the FotaHub® Device SDK for Linux® and Raspberry Pi even on a Windows&reg; or Mac&reg; OS X machine by using [Windows Subsystem for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl) or [Docker Desktop](https://www.docker.com/products/docker-desktop).

# Installation
To use the FotaHub&reg; Device SDK for Linux&reg; and Raspberry Pi, the following tools must be available on your laptop or computer:
* A GCC compiler/linker toolchain
* A [Python 3](https://www.python.org/downloads) interpreter
* A text editor or IDE of your choice, e.g., [Visual Studio Code](https://code.visualstudio.com)

# Getting started
The best way to get started with the FotaHub&reg; Device SDK for Linux&reg; and Raspberry Pi is to try out and study the included examples:
* [Simple](docs/getting-started/simple.md) - "Hello World" of firmware over-the-air updating with FotaHub&reg;
* [Rollbackable](docs/getting-started/rollbackable.md) - Downloads and launches a new firmware version provided at FotaHub&reg;, rolls it back to the previous version if something goes wrong
* [Thing Shadow](docs/getting-started/thingshadow.md) - A real-world scenario where FotaHub&reg; is used in combination with the AWS IoT Thing Shadow service to trigger firmware updates over-the-air updates through the cloud

# API Reference
View the [C API reference](include/FotaHub.h) for detailed information about the FotaHub&reg; client library (:construction: *under construction*).

# License and third-party software
Unless specifically indicated otherwise in a file included in this project, FotaHub&reg; Device SDK for Linux&reg; and Raspberry Pi files are provided under the *Apache-2.0* license. See the [LICENSE](LICENSE) file for the full text of this license.

The terms of the license attributed to this project do not alter any rights or obligations you may have under the licenses of any third-party software which is redistributed through the present project. Refer to the [NOTICE](NOTICE.md) file for detailed information regarding these aspects.
