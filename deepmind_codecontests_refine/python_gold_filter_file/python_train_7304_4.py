cond = [int(x) for x in input().split()]
n = cond[0]
p = cond[1]
k = cond[2]
a = [int(x) for x in input().split()]
b = [(x**4-k*x)%p for x in a]
d = {}
r = 0
for x in b:
	if x not in d:
		d[x] = 0
	r += d[x]
	d[x] += 1
print(r)
