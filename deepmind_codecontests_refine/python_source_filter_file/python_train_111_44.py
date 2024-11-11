import sys
import math

n=int(input())
lisa=[int(x) for x in input().strip().split()]
suma=sum(lisa)
amax=max(lisa)
for i in range(amax,101):
    #print("i=",i)
    if(i*n-suma>=suma):
        print(i)
        break
