# cook your dish here
#import sys
#sys.setrecursionlimit(10**9) 
ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
lx=lambda x:map(int,input().split(x))
yy=lambda:print("YES")
nn=lambda:print("NO")

from math import log10 ,log2,ceil,factorial as fac,gcd,inf,sqrt,log
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
from bisect import bisect_right as br,bisect_left as bl,insort
from collections import Counter
#from math import inf


mod=10**9+7


def Nprime(n):
    if n==2 or n==3:
        return 0
    if n==1:
        return 1
    i=2
    while i*i<=n:
        if n%i==0:
            return 1
        i+=1
    return 0

def sum_(a,n):
    d=4
    s=(n*(2*a+(n-1)*d))//2
    return s
    
def aux(x,y):
    if x=='a' and y=='z':
        return 1
    if y=='a' and x=="z":
        return 1
    return abs(ord(x)-ord(y))
def aux1(x,y):
    if x=='a' and y=='z':
        return 1
    if y=='z' and x=='a':
        return 1
    return ord('z')-ord(y)+ord(x)-ord('a')
for _ in range(t()):
    
#def f():

    

    a,b=ll()
    c,d=ll()
    
    x,y=str(a),str(c)
    if len(x)+b>len(y)+d:
        print(">")
    elif len(x)+b<len(y)+d:
        print("<")
    else:
        if b>d:
            x=x+"0"*(b-d)
        elif d<b:
            y=y+'0'*(d-b)
        if int(x)>int(y):
            print(">")
        elif int(y)>int(x):
            print("<")
        else:
            print("=")
        
            
'''
p m

5 9
3 7
1 5

3 2
49 1

dist[child]=dist[parent]+dist[node]

'''

    
    
    

        
            
    
#f()
    

'''
\


1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7
-5 -4 -3 -2 -1 0 1 2 3 4 5 6


0 1 2 3-3
4 5 6 7-7


'''
