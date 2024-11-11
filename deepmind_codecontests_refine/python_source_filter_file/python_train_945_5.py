"""[summary]
Codeforces Round  # 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)
"""
from math import sqrt

pairs = []
n = int(input())
for _ in range(n):
    a, b = list(map(int, input().split()))
    pairs.append((a,b))

def PF(n, set):
    for i in range(2, int(sqrt(n))+1, 1):
        # while i divides n 
        if (n % i == 0):
            set.add(i)
        while n % i == 0:
            n /= i
    if n > 2:
        set.add(n)

prime = set()
PF(pairs[0][0], prime)
PF(pairs[0][1], prime)

# check if there is WCD
for a, b in pairs[1:]:
    tmp = set()
    for i in prime:
        if a % i == 0 or b % i == 0:
            tmp.add(i)
    prime = prime.intersection(tmp)

if len(prime) > 0:
    print(prime.pop())
else:
    print(-1)
