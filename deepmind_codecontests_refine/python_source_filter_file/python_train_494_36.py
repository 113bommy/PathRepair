#E
from fractions import gcd
N=int(input())

mod=1000000007
ans=1
P=dict()
M=dict()
zero=0
zero1=0
zero2=0
for i in range(N):
    a,b=map(int,input().split())
    if a==0 and b==0:
        zero+=1
    elif a==0 and b!=0:
        zero1+=1
    elif a!=0 and b==0:
        zero2+=1
    elif (a>0 and b<0) or (a<0 and b>0):
        GCD=gcd(abs(a),abs(b))
        a=abs(a)//GCD
        b=abs(b)//GCD
        s=str(a)+"/"+str(b)
        P[s]=P.get(s,0)+1
        
    else:
        GCD=gcd(abs(a),abs(b))
        a=abs(a)//GCD
        b=abs(b)//GCD
        s=str(b)+"/"+str(a)
        M[s]=M.get(s,0)+1

P["0/0"]=zero1
M["0/0"]=zero2
for v,cnt_p in P.items():
    if v in M:
        cnt_m=M[v]
        ans*=(2**cnt_p+2**cnt_m-1)
        M.pop(v)
    else:
        ans*=2**cnt_p
    ans%=mod
    
for v,cnt_m in M.items():
    ans*=2**cnt_m
    ans%=mod

ans-=1
ans+=zero
ans%=mod
print(ans)