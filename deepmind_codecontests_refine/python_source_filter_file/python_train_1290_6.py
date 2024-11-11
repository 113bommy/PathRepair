#_________________ Mukul Mohan Varshney _______________#

#Template
import sys
import os
import math
import copy
from math import gcd
from bisect import bisect
from io import BytesIO, IOBase
from math import sqrt,floor,factorial,gcd,log,ceil
from collections import deque,Counter,defaultdict
from itertools import permutations, combinations

#define function 
def Int(): return int(sys.stdin.readline())
def Mint(): return map(int,sys.stdin.readline().split())
def Lstr(): return list(sys.stdin.readline().strip())
def Str(): return sys.stdin.readline().strip()
def Mstr(): return map(str,sys.stdin.readline().strip().split())
def List(): return list(map(int,sys.stdin.readline().split()))
def Hash(): return dict()
def Mod(): return 1000000007
def Ncr(n,r,p): return ((fact[n])*((ifact[r]*ifact[n-r])%p))%p
def Most_frequent(list): return max(set(list), key = list.count)
def Mat2x2(n): return [List() for _ in range(n)]
def btod(n): 
    return int(n,2) 
    
def dtob(n): 
    return bin(n).replace("0b","")    

 
# Driver Code 	
def solution():
     #for _ in range(Int()):
          x,y,m=Mint()
          ans=0
          if(x>=m or y>=m):
               print(0)
          elif(x<=0 and y<=0):
               print(-1)
          else:
               if(x>0 and y<0):
                    ans=(x-y-1)/x
                    y+=ans*x
               elif(y>0 and x<0):
                    ans=(y-x-1)/y
                    x+=ans*y 
               while(x<m and y<m):
                    t=x+y
                    if(x<y):
                         x=t
                    else:
                         y=t
                    ans+=1     
               print(int(ans))          
               
          
          
#Call the solve function          
if __name__ == "__main__":
     solution()  