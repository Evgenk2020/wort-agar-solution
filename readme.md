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
</p>

# Nutrition medium dilution

Lab utility for determining the concentration of a wort agar medium solution via preparing from natural raw components

Run it with specified keys

```

wort -d | -df [data...]

```

Using `-df` key you may write data to `*.csv` file for the next importing to LibreOffice Calc, MS Excell or Google Tables

![Google table data import](/img/screen.png)

Use `build.sh` and `run.sh` from the `src` folder to compile and run the application

For more convenience you may add path to the application into `.bashrc` file

```

export PATH=$PATH:/%path_to_application_folder%/

```

and then use simple SH schemes e.g.

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
