import sys
import os

files = os.listdir()

for file in files:
    if file != "renamed":
        with open(file, "r") as f:
            new_filename = file.replace(".txt-", "-")
            contents = f.read()
            new_file = open("renamed/"+new_filename, "w")
            new_file.write(contents)
            new_file.close()