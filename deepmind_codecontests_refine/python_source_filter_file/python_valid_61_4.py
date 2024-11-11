import sys
import math
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    a=input().strip()
    if a=="?"*n:
        a=a.replace("?","R",1)
    while "?" in a:
        a=a.replace("R?","RB")
        a=a.replace("B?","RB")
        a=a.replace("?R","BR")
        a=a.replace("?B","RB")
    print(a)