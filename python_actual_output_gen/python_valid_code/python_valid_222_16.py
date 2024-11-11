import sys
n = int(input())
T = [line.split() for line in sys.stdin.readlines()]
res = 0
for i, t in enumerate(sorted([(int(a) + int(b), int(b)) for a, b in T])):
	if i % 2 == 0:
		res += t[0]
	res -= t[1]

print(res)
