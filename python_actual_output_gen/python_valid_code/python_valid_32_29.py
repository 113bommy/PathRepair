n, a = map(int,input().split())
b = list(x for x in input())
c =[]
for x in range(int(a)):
	if len(b) == 0:
		break
	c.append(b[0])
	b.pop(0)
if n < a:n = a
for _ in range(n // a):
	for y in range(len(c)):
		for x in b:
			if x not in c[y]:
				c[y] += x
				b.remove(x)
				break
b.append("")
if b [0] == "": print("YES")
else:print("NO")
