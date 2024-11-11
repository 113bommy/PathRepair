def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())

def check(n):
    f=ru
    if B*n>a:
        f-=(B*mid-a)*p 
    if S*n>b:
        f-=(S*mid-b)*q 
    if C*n>c:
        f-=(C*mid-c)*r
    
    if f>=0:
        return True 
    else:
        return False

import math 

for i in range(1):
    s=si()
    a,b,c=mi()
    p,q,r=mi()
    ru=ii()
    
    B=s.count('B')
    S=s.count('S')
    C=s.count('C')
    
    lo=0
    hi=1000000000000 
    while(lo<=hi):
        mid=(lo+hi)//2 
        if check(mid):
            ans=mid
            lo=mid+1 
        else:
            hi=mid-1 
    print(ans)