import bisect

from math import sqrt

maxn = int(1e5)
isprime = [1 for i in range(maxn+1)]

d =  [1E9 for i in range(maxn+1)]

def sieve():
    cross_limit = int(sqrt(maxn))
    isprime[0] = isprime[1]= 0
    for i in range(4, maxn+1, 2):
        isprime[i] = 0
    for i in range(3, cross_limit+1, 2):
        if isprime[i]:
            for j in range(i*i, maxn+1, 2*i):
                isprime[j] = 0

sieve()

dst = 0
for i in range(maxn, 0, -1):
    if isprime[i]: dst = 0
    d[i] = min(d[i], dst)
    dst += 1

n, m = list(map(int, input().split()))
matrix = [list(map(int, input().split())) for i in range(n)]

rows = (sum(map(lambda x: d[x], matrix[i])) for i in range(n))
column = (sum((d[matrix[i][j]] for i in range(n))) for j in range(m))

print(min(min(rows), min(column)))


