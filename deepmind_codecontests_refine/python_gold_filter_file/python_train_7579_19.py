n, k = map(int, input().split())
hs = [int(input()) for _ in range(n)]
hs.sort()
print(min(hs[i + k - 1] - hs[i] for i in range(n - k + 1)))
