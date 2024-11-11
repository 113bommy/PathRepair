import sys
def input():
	return sys.stdin.readline()[:-1]
n = int(input())
plus, minus = [], []
for _ in range(n):
	s = input()
	mi, cur = 0, 0
	for i in range(len(s)):
		if s[i] == "(":
			cur += 1
		else:
			cur -= 1
		mi = min(mi, cur)
	if cur >= 0:
		plus.append((mi, cur))
	else:
		minus.append((mi, cur))

plus.sort(key=lambda x: -x[0])
minus.sort(key=lambda x: x[0] - x[1])
res = plus + minus

cur = 0
for m, t in res:
	if cur + m < 0:
		print("No")
		exit()
	cur += t

if cur != 0:
	print("No")
	exit()
print("Yes")