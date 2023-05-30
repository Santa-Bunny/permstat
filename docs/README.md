# PermStat
### A permissions manager in gui form

## Overview

While performing server maintenance I often found myself going directory by directory adjusting permissions
on a file by file basis. I found myself wishing that I had something akin to [WinDirStat](https://windirstat.net/) or [QDirStat](https://github.com/shundhammer/qdirstat). There was no such thing on the market, and so I got to planning. Though I originally wanted something more graphical, I realised that I would often be working out of my hypervisor and on servers without GUIs. Thus I decided to work more towards a system like [ncdu](https://dev.yorhel.nl/ncdu). 

The end goal is to have a NCDU like interface with colored text that can display at a glance the permissions of each file and directory. There are many options for extras to increase productivity such as filters and searching; however the primary focus at this point in development is functionality and end-user QOL.


## NCurses

NCurses was chosen over other similar application types like Xterm for its backportability on all machine types and operating systems.