n, k = map(int, input().strip().split())

mod = (10 ** 9 + 7)

hashmap = [1 for a in range(0, k)]

for a in range(k, 100000 + 1):
	hashmap.append(hashmap[a - k] % mod + hashmap[a - 1] % mod)
for d in range(1, len(hashmap)):
	hashmap[d] += hashmap[d - 1]
# print(hashmap)

for a in range(0, n):
	i, j = map(int, input().strip().split())

	print(hashmap[j] - hashmap[i - 1])