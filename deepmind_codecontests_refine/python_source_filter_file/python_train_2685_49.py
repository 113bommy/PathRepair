import fractions
from functools import reduce
n,m=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=a[i]//2
def lcm_base(x,y):
    return (x*y)//fractions.gcd(x,y)
def lcm_list(numbers):
    return reduce(lcm_base,numbers,1)
f2=lcm_list(a)

ans=0
for i in range(n):
    if f2/a[i]%2!=1:
        print(ans)
        break
else:
    ans=m//f2
    print((ans+1)//2)