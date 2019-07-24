from csv2txt import *
import pandas as pd
import os
from tempfile import mkstemp
from shutil import move
from os import fdopen, remove

def replace(file_path, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    with fdopen(fh,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(line.replace(pattern, subst))
    #Remove original file
    remove(file_path)
    #Move new file
    move(abs_path, file_path)

def csv2xlsx(path, filename, delimiter):
    csv2txt(filename, delimiter)
    name = path + '\\' + filename
    pd.read_csv(name + '.txt', delimiter=delimiter, encoding='latin-1').to_excel(name + ".xlsx", index=False)
    os.remove(filename + ".csv")
    os.remove(filename + ".txt")
    return

