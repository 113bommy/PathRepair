from math import gcd,sqrt
n=int(input())
t=0
for i in range(1,int(sqrt(n))+1):
    if n%i==0:
        a=i
        b=n//i
        GCD=gcd(a,b)
        if GCD==1:
            t=i
            break
print(t,n//t)