n=int(input())

mod=10**9+7

#初期値が0の辞書
from collections import defaultdict
pp = defaultdict(lambda: 0) 
pm = defaultdict(lambda: 0) 

def seiki(x,y):
    tmp=gcd(x,y)
    return (x//tmp,y//tmp)

from math import gcd
zero=0
for _ in range(n):
    a,b=map(int,input().split())

    if a==0 and b==0:
        zero+=1
    elif a*b>0:
        tmp=seiki(abs(a),abs(b))
        pp[tmp]+=1
    elif a==0:
        pp[(1,0)]+=1
    elif b==0:
        pm[(1,0)]+=1
        pp[(1,0)]+=1
    else:
        tmp=seiki(abs(b),abs(a))
        pm[tmp]+=1
        pp[tmp]+=0
#print(pm)
#print(pp)
result=1
for key in pp.keys():
    pp_v=pp[key]
    pm_v=pm[key]
    result*=(pow(2,pm_v,mod)+pow(2,pp_v,mod)-1)
    result%=mod

print((result-1+zero)%mod)


    

    