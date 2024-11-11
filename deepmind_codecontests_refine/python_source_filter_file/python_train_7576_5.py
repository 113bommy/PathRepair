import fractions
N=int(input())
A=list(map(int,input().split()))
c=1
a=0
w=10**9+7
for A_ in A:
    c=c*A_//fractions.gcd(c,A_)
for A_ in A:
    a+=c//A_
print(int(a%w))
