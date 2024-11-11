import fractions
import collections
A,B = map(int,input().split())
p = fractions.gcd(A,B)
#print(p)
num = []
for i in range(2,int(p**0.5)+1):
    while p%i==0:
        num.append(i)
        p //= i
if p != 1:
    num.append(p)
#print(num)
pp = collections.Counter(num)
print(len(pp)+1)