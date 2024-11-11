N, L = map(int,input().split())
S = sorted([input() for i in range(n)])
print(*S, sep="")