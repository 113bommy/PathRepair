N,K,S = map(int,input().split())

MAXA = 10**9

ans = [S] * K + [MAXA] * (N-K)
print(*ans)