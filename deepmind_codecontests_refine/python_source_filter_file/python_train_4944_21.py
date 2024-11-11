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
from bisect import bisect_right as br,bisect_left as bl
from collections import Counter
#from math import inf


mod=10**9+7


    
#for _ in range(t()):
    
def f():
    

    n=t()
    
    k1,*a=list(ll())
    k2,*b=list(ll())

    q=[]
    c=0
    q.append([a.copy(),b.copy()])
    print(q)
    while len(a) and len(b):
        c+=1
        x,y=a.pop(0),b.pop(0)
    
        if x>y:
            a.append(y)
            a.append(x)

        else:
            b.append(x)
            b.append(y)
            
        #print(a,b)
        if [a,b] not in q:
            q.append([a.copy(),b.copy()])

        else:
            #print(q,[a,b])
            print(-1)
            break
        
    
        
        
    else:
        print(c,[1,2][len(b)>0])
f()
    

'''

baca

bac
1 2 3
baaccca

abbaccccaba
 
'''
