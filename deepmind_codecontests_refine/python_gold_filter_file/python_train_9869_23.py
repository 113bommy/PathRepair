A,B = map(int,input().split())
from fractions import gcd
C = gcd(A,B)
num = []
for i in range(2,int(C**0.5)+1):
    while C%i==0:
        num.append(i)
        C //= i
if C != 1:
    num.append(C)
from collections import Counter
CC = Counter(num)
print(len(CC)+1)