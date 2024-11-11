S = input()
T = input()
q = int(input())

s = [0]
t = [0]
v = 0
for c in S:
	v = (v + (ord(c) - ord("A") + 1)) % 3
	s.append(v)
v = 0
for c in T:
	v = (v + (ord(c) - ord("A") + 1)) % 3
	t.append(v)

for i in range(q):
	a,b,c,d = map(int, input().split())
	x = (3 + s[b] - s[a-1]) % 3
	y = (3 + t[d] - s[c-1]) % 3
	if x == y:
		print("YES")
	else:
		print("NO")
