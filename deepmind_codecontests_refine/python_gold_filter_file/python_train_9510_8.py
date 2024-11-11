import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

n=int(input())
time=list(map(int,input().split()))
a=min(time)
if(time.count(a)> 1):
    print('Still Rozdil')
else:
    print(time.index(a) + 1)
