from fraction import gcd
a=int(input())
s=int(input())
k=s
for i in range(a-1):
    d=int(input())
    k=(k*d)//gcd(k,d)
print(k)