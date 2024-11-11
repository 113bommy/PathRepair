n, k = map(int, input().split())
counts = list(map(int, input().split()))

if (max(counts) - min(counts)) > k:
	print('NO')
	exit()

print('YES')
i = min(counts)
piles = [[1] * i for _ in counts]
for count, pile in zip(counts, piles):
	pile.extend(range(1, count - i))
for pile in piles:
	print(' '.join(map(str, pile)))
