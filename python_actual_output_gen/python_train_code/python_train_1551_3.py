N, K = map(int, input().split())
ans = 0
for i in range(K, N+2):
    ans += i * (N-i+1) + 1
print(ans%(10**7+7))