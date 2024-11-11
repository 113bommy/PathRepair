__author__ = 'taras-sereda'

from pprint import pprint as pp

n = int(input())

maxn = 1010
mod = 1000000007
coef = [[0 for i in range(maxn)]for i in range(maxn)]

for i in range(maxn):
    coef[i][0] = 1
    for j in range(1, maxn):
        coef[i][j] = (coef[i-1][j] + coef[i-1][j-1]) % mod

colors = [int(input()) for i in range(n)]

res = 1
total = 0

for i in range(n):
    res *= coef[total+colors[i]-1][colors[i]-1] % mod
    total += colors[i]
print(res)
