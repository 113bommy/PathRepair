from fractions import*
n=gcd(*map(int,input().split()))
a=1
i=2
while i*i<=n:
 a+=n%i<1
 while n%i<1:n//=i
 i+=1
print(a+(n>1))