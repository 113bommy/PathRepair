from collections import Counter
N = int(input())
S = Counter(input() for _ in range(N))
m = max(S.values())
for v in sorted(s for k, v in S.items() if v == m):
	print(v)