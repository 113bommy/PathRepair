from fractions import*
n=gcd(*map(int,input().split()))
a=i=1
while i*i<n:
 i+=1;a+=n%i<1
 while n%i<1:n/=i
print(a)