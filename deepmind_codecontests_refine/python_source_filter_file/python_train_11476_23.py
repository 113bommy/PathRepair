from sys import stdin, stdout
from math import *
from heapq import *
from collections import *

def main():
    n,m=[int(x) for x in stdin.readline().split()]
    a=[(int(x)%m) for x in stdin.readline().split()]
    if (n<=(m*2)):
        outp=1
        for i in range(n):
            for j in range(i+1,n):
                outp=(outp*abs(a[i]-a[j]))%m
        stdout.write("%d"%outp)
    else:
        stdout.write('0')
    return 0

if __name__ == "__main__":
    main()