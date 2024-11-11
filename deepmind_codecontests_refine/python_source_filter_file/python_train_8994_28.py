from sys import stdin,stdout
from collections import Counter
from math import ceil
from bisect import bisect_left 
from bisect import bisect_right
import math

def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(ans): return stdout.write(str(ans) + '\n')

n,m=ei()
ls=ai()
ls.sort()
c=0
k=0
if 1 in ls or n in ls:
    print("No")
else:
    for i in range(len(ls)-1):
       #ls[i]-ls[i+1],ls[i],ls[i-1]
        if abs(ls[i]-ls[i+1])==1:
            c+=1 
        else:
            c=0
        
        if c==2:
            print("No")
            k=1 
            break
    if k==0:
        print("Yes")