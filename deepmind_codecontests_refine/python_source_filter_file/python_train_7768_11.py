n, x = map(int, input().split())
encoding = list(map(int, input().split()))

total = 0
for i, v in enumerate(encoding):
	total += v
	if i != len(encoding) - 1:
		total += 1

print('YES' if total <= x else 'NO')