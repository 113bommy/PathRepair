import sys
from math import log
input = sys.stdin.readline
n,q = map(int,input().split())
coins = list(map(int,input().split()))
freq = [0 for i in range(32)]
for coin in coins: freq[int(log(coin, 2))]+=1
for j in range(q):
    b = int(input())
    c = 0
    for i in range(8, -1, -1):
        k = b//2**i
        b -= min(k, freq[i])*(2**i)
        c += min(k, freq[i])
    if b: print(-1)
    else: print(c)
