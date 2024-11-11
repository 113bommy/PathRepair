from math import *
from bisect import *
from collections import Counter,defaultdict,deque
from sys import stdin, stdout
input = stdin.readline
I=lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
for _ in range(1):
  n,a,b=M()
  ans=-1
  for i in range(1,max(a,b)):
    if a//i + b//i >=n:
      ans=max(ans,i)
  print(ans)
























        
        
            


        



    









    

            







        
