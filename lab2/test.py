#!/usr/bin/python
import subprocess
import sys

print(sys.argv)

filename = 'test.txt'
name = 'main.o'
if len(sys.argv) > 1:
    name = sys.argv[1].split()[0]
    count = sys.argv[1].split()[1]
if len(sys.argv) > 2:
    filename = sys.argv[2]

f = open(f'{filename + " " + count}.txt', 'w')

for i in range(1000):
    pipe = subprocess.Popen(f"./{name}", shell=True, stdout=subprocess.PIPE).stdout
    output = pipe.read()
    s = str(output).split("'")[1]
    f.write(s[:len(s)-2] + '\n')

f.close()