from collections import defaultdict

n = int(input())

d = defaultdict(int)

for _ in range(n):
	a, b = [int(x) for x in input().split()]
	d[a+b] += 1
	d[a-b+3000] += 1

sm = 0
for v in d.values():
	sm = sm + (v*(v-1))//2

print(sm)

