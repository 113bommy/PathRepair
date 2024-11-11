import os
import sys

def main():
    n = int(input())
    for i in range(1,n+1):
        x = int(input())
        print("Case {}:".format(i))
        for j in range(10):
            x = x**2
            out = '{0:08d}'.format(x)
            print(out[2:6])
            x = int(out[2:6])

main()