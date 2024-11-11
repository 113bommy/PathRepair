import sys
import math

x,y=map(int,input().split())
n=int(input())
f1,f2=x,y
comma=[f1,f2,f2-f1,-1*f1,-1*f2,f1-f2]
print(comma[(n-1)%6]%10000007)