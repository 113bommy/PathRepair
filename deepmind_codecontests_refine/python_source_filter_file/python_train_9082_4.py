from math import *
from bisect import *
from collections import Counter,defaultdict,deque
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
for _ in range(I()):
  l,r,m=M()
  c=r-l
  if m<l:
    print(l,l,r-(m-1))
  else:
    for i in range(l,r+1):
      if (m%i)+c>=i:
        print(i,l,l+(i-(m%i)));break
      elif m%i<=c:
        print(i,l+(m%i),l);break














        
        
            


        



    









    

            







        
