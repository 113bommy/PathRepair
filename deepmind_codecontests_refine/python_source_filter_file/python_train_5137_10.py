from sys import stdin,stdout
from math import gcd
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
def fn(s,n,k):
    for i in range(k,n):
        if s[i]!=s1[i%k]:return False
    return True
for i in range(1):#nmbr()):
    s1=input()
    s2=input()
    n1=len(s1)
    n2=len(s2)
    if n1>n2:
        s1,s2=s2,s1
        n1,n2=n2,n1
    p=1
    rep=n1
    while p*p<=n1:
        if n1%p==0:
            rep=min(rep,p if fn(s1,n1,p) else n1)
            if p!=(n1//p):rep=min(rep,n1//p if fn(s1,n1,n1//p) else n1)
        p+=1
    print(rep)
    f=1
    for i in range(n2):
        if s2[i]!=s1[i%rep]:
            f=0
            break
    if f==0 or n2%n1!=0:
        print(0)
        continue
    ans=0
    p=1
    rep=gcd(n1//rep,n2//rep)
    while p*p<=rep:
        if rep%p==0:
            ans+=1
            if p!=(rep//p):ans+=1
        p+=1
    print(ans)