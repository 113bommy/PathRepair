import sys

readline = sys.stdin.readline
t = int(readline())
for _ in range(t):
    n, r = map(int, readline().split())
    x = min(n, r)
    if n <= r:
        print((n*(n-1))//2+1)
    else:
        print(r*(r+1)//2)
