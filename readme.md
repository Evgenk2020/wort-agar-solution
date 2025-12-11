<p align="center">
  <a href="https://github.com/Evgenk2020/wort-agar-solution/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/Evgenk2020/wort-agar-solution" alt="license">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution/commits">
    <img src="https://img.shields.io/github/last-commit/Evgenk2020/wort-agar-solution" alt="last commit">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution">
    <img src="https://img.shields.io/github/repo-size/Evgenk2020/wort-agar-solution" alt="repo size">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution/stargazers">
    <img src="https://img.shields.io/github/stars/Evgenk2020/wort-agar-solution" alt="stars">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution/network/members">
    <img src="https://img.shields.io/github/forks/Evgenk2020/wort-agar-solution" alt="forks">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution">
    <img src="https://img.shields.io/github/languages/top/Evgenk2020/wort-agar-solution" alt="top language">
  </a>
  <a href="https://github.com/Evgenk2020/wort-agar-solution/releases">
    <img src="https://img.shields.io/github/v/release/Evgenk2020/wort-agar-solution" alt="latest release">
  </a>
  <!-- Added version badge -->
  <a href="https://github.com/Evgenk2020/wort-agar-solution">
    <img src="https://img.shields.io/badge/version-1.0.2-blue" alt="version">
  </a>
</p>

# Nutrition medium dilution

Lab utility for determining the concentration of a wort agar medium solution via preparing from natural raw components

Run it with specified keys

```

wort -d | -df [data...]

```

Using `-df` key you may write data to `*.csv` file for the next importing to LibreOffice Calc, MS Excell or Google Tables

![Google table data import](/.img/screen.png)


.sh file example for running in terminal

```SH

#!/bin/bash

wort -d 21 4.5 300
echo "----------------"
wort -d 21 3 250
echo "----------------"
wort -d 15 4.5 200
echo "----------------"
wort -d 20 5 280
echo "----------------"
wort -d 20.5 4.5 250

exec $SHELL

```

or for writing `.csv` use

```SH

#!/bin/bash

wort -df 21 4.5 300 
wort -df 21 3 250
wort -df 15 4.5 200
wort -df 20 5 280
wort -df 20.5 4.5 250

exec $SHELL

```
<hr>

> You need
> <br>
> [CMake](https://cmake.org/)
> <br>
> to be installed on your Linux system previously

<hr>

<b>To compile and run the utility</b>

1. Clone the Repository

```SH

git clone https://github.com/Evgenk2020/wort-agar-solution

cd wort-agar-solution

```

2. Check for `rpm-build` package to be installed in your system

```SH

rpm -q rpm-build

```

If so you will see `rpm-build-6.0.0-1.fc43.x86_64` or something like that.

If not it will be `package rpm-build is not installed`. Then install it from system repository

```SH

sudo dnf install rpm-build

```

3. Build the Project with `.rpm` setup package for Fedora/CentOS Stream by default

```SH

./build.sh

```

4. Install `.rpm` package from build folder

```SH

sudo dnf install *.rpm

```

If using either than Fedora/CentOS Stream change the first string `set(assemble_tgz OFF)` in CMakeLists.txt to `set(assemble_tgz ON)` before building the Project. Move `.tar.gz` file to any folder and unpack it.

Then run `./wort -d | -df [data...]` in terminal from unpacked folder.

For more convenience you may add path to the application into `.bashrc` file

```SH

export PATH=$PATH:/%path_to_application_folder%/

```

In this case it will be possible to run `wort -d | -df [data...]` in terminal directly.
