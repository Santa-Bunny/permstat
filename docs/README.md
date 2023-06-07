# PermStat
### A permissions manager in gui form

## Note: This project is still not fully functional. For the latest updates check the Dev branch.

## Overview

While performing server maintenance I often found myself going directory by directory adjusting permissions
on a file by file basis. I found myself wishing that I had something akin to [WinDirStat](https://windirstat.net/) or [QDirStat](https://github.com/shundhammer/qdirstat). There was no such thing on the market, and so I got to planning. Though I originally wanted something more graphical, I realised that I would often be working out of my hypervisor and on servers without GUIs. Thus I decided to work more towards a system like [ncdu](https://dev.yorhel.nl/ncdu). 

The end goal is to have a NCDU like interface with colored text that can display at a glance the permissions of each file and directory. There are many options for extras to increase productivity such as filters and searching; however the primary focus at this point in development is functionality and end-user QOL.

## Dependencies

#### Ncurses
You must have NCurses library installed to be able to use permstat. 
If you choose to build permstat from source your compiler will also need to have the `-lncurses` flag

#### Boost.Filesystem
The scanning method relies on Boost::Filesystem.
Boost filesystem needs to be precompiled into a binary with Boost Build before it can be used in compilation of permstat.
Please follow [Boost Getting Started](https://www.boost.org/doc/libs/1_82_0/more/getting_started) to learn how to compile the filesystem binary.