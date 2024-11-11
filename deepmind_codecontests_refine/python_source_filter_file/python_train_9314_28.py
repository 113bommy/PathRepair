import sys
import math
from collections import Counter
from collections import OrderedDict
sys.setrecursionlimit(10**6)
def inputt():
    return sys.stdin.readline().strip()
def printt(n):
    sys.stdout.write(str(n)+'\n')
def listt():
    return [int(i) for i in inputt().split()]
 
def gcd(a,b): 
   return math.gcd(a,b) 
 
def lcm(a,b): 
    return (a*b) // gcd(a,b) 

n,x,y=map(int,inputt().split())
li=[]
count=0
for i in range(n):
    s,t=map(int,inputt().split())
    if x!=s:
        li.append(abs((t-y)/(s-x)))
    else:
        count=1    
dic=Counter(li)
printt(len(dic.keys())+count)    


