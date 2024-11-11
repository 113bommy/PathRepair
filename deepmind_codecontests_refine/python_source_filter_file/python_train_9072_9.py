import math
mod=1000000007
def power(a,b):
    res=1
    b=b%(mod-1)
    while(b>0):
        if b%2!=0:
            res=((res%mod)*(a%mod))%mod
        b=b//2
        a=a%mod
        a=(a*a)%mod
    res=res%mod
    return res
#n=int(input())
#a=[int(i) for i in input().split()]
#c=[[0 for x in range(1001)] for y in range(1001)]
#n,q=[int(i) for i in input().split()]
#a.sort(reverse=True)
n=int(input())
m=math.ceil((n+1)/2)
print(m)
for i in range(1,m+1):
    print(1,i)
    n-=1
    if n==0:
        break
if n>0:
    for i in range(1,m+1):
        print(m,i)
        n-=1
        if n==0:
            break