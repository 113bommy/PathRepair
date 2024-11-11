n=int(input())
m=[list(map(int,input().split())) for i in range(n)]
from math import gcd, sqrt
gc=m[0][1]
c=m[0]
for i in range(2,n):
    gc=gcd(gc,m[0][i])
def divisors(n):
    divs = [1]
    for i in range(2,int(sqrt(n))+1):
        if n%i == 0:
            divs.extend([i,n/i])
    divs.extend([n])
    return list(set(divs))
a=divisors(gc)
a.sort()
a.reverse()
def chk(k):
    t=True
    ans=list(c)
    for i in range(n):
        ans[i]=int(ans[i]/k)
    ans[0]=k
    for i in range(n):
        for j in range(n):
            if i!=j and ans[i]*ans[j]!=m[i][j]:
                t=False
                break
        if t==False:
            break
    return t
ans=[]
for rr in range(len(a)):
    if chk(int(a[rr])):
        ans=list(c)
        for i in range(n):
            ans[i]=int(ans[i]/a[rr])
        ans[0]=a[rr]
        break
for i in ans:
    print(i,end=" ")
