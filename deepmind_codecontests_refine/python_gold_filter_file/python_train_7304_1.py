from collections import Counter

n, p, k = map(int, input().split())
a = list(map(int, input().split()))
freqs = Counter([(x ** 4 - k * x) % p for x in a])
ans = sum([(x - 1) * x // 2 for x in freqs.values()])
print(ans)