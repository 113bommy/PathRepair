from sys import stdin ,stdout
from os import path
rd = lambda:stdin.readline().strip()
wr = stdout.write
if(path.exists('input.txt')):
    stdin = open("input.txt","r")
import time 
#------------------------------------
x,y = map(int,rd().split())
arr = [(abs(((y+1)//2)-(k+1)),k+1) for k in range(y)]
arr.sort()
for i in range(x):
	ind = i%y
	print(arr[ind][1])