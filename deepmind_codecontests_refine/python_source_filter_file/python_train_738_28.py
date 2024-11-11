from math import *
from sys import stdin,stdout
z=int(stdin.readline())
if (z%2==0):
    stdout.write(str(z//2))
else:
    for i in range(2,ceil(sqrt(z))):
        if (z%i==0):stdout.write(str(1+(z-i)//2));exit()
    stdout.write('1')
