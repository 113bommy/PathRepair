N, K = map(int, input().split())
ans = N - K
ans += 1 if k == 1 else 0
print(ans)