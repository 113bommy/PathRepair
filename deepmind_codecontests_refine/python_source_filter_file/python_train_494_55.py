N=int(input())
from collections import defaultdict
dic=defaultdict(int)
dic[(0,0)]=dic[(0,1)]=0
import math
mod=1000000007
for _ in range(N):
    A,B=map(int,input().split())
    if A<0:
        A,B=-A,-B
    if A==0:
        if B==0:
            dic[(0,0)]+=1
        else:
            dic[(0,1)]+=1
    elif B==0:
        dic[(1,0)]+=1
    else:
        gcd=math.gcd(A,B)
        A,B=A//gcd,B//gcd
        dic[(A,B)]+=1

ans=1
N-=dic[(0,0)]
for k,v in dic.items():
    if k==(0,0) or k==(0,1):
        continue
    if k==(1,0):
        v_dash=dic[(0,1)]
        ans*=((pow(2,v,mod)-1)+(pow(2,v_dash,mod)-1)+1)
        ans%=mod
        N-=v+v_dash
        continue
    a,b=k
    if not (b,-a) in dic:
        continue
    v_dash=dic[(b,-a)]
    ans*=((pow(2,v,mod)-1)+(pow(2,v_dash,mod)-1)+1)
    ans%=mod
    N-=v+v_dash
ans*=pow(2,N,mod)
ans+=dic[(0,0)]
ans%=mod
print(ans-1)
