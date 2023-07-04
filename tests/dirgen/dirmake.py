import os
import traceback


try:
    #parent dirs
    os.mkdir("./root_node")
    os.mkdir("./root_node/dir1")
    os.mkdir("./root_node/dir2")
    os.mkdir("./root_node/dir3")
    os.mkdir("./root_node/dir4")

    #child dirs
    os.mkdir("./root_node/dir1/dir1dir1")
    os.mkdir("./root_node/dir1/dir1dir2")
    os.mkdir("./root_node/dir3/dir3dir1")
    os.mkdir("./root_node/dir3/dir3dir1/dir3dir1dir1")
    os.mkdir("./root_node/dir3/dir3dir2")

    datafile = open("./../dirgen/data.txt", "r")
    f1 = open("./root_node/file1.txt", "w")
    f1.write(datafile.readline() + datafile.readline())
    f1.close()

    f11 = open("./root_node/dir1/dir1file1.txt", "w")
    f11.write(datafile.readline())
    f11.close()

    f12 = open("./root_node/dir1/dir1file2.txt", "w")
    f12.write(datafile.readline() + '\n' + datafile.readline())
    f12.close()

    f13 = open("./root_node/dir1/dir1file3.txt", "w")
    f13.write(datafile.readline())
    f13.close()

    f121 = open("./root_node/dir1/dir1dir2/file1.txt", "w")
    f121.write(datafile.readline())
    f121.close()

    f122 = open("./root_node/dir1/dir1dir2/file2.txt", "w")
    f122.write(datafile.readline())
    f122.close()

    f21 = open("./root_node/dir2/dir2file1.txt", "w")
    f21.write(datafile.readline())
    f21.close()

    f31 = open("./root_node/dir3/dir3file1.txt", "w")
    f31.write(datafile.readline())
    f31.close()

    f311 = open("./root_node/dir3/dir3dir1/file1.txt", "w")
    f311.write(datafile.readline())
    f311.close()

    f312 = open("./root_node/dir3/dir3dir1/file2.txt", "w")
    f312.write(datafile.readline())
    f312.close()

    f311 = open("./root_node/dir3/dir3dir1/dir3dir1dir1/file1.txt", "w")
    f311.write(datafile.readline() + '\n' + datafile.readline() + '\n' + datafile.readline() + '\n' + datafile.readline())
    f311.close()

    datafile.close()

except Exception:
    traceback.print_exc()