n = int(input())
s = [int(i) for i in input().split()]
e = set()
d = []
c = 0

for i in range(2*n):
	if s[i] in e:
		d.append(c)
		c -= 1
	else:
		e.add(s[i])
		c+=1

print(max(d))
