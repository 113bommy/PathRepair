n = int(input())
i = 0
l = [int(1e9)]*(int(1e6+1))
r = [-1]*(int(1e6+1))
c = [0]*(int(1e6+1))
mc = 0
for x in map(int, input().split()):
	l[x] = min(l[x], i)
	r[x] = max(r[x], i)
	c[x] += 1
	mc = max(mc, c[x])
	i += 1
res = (int(1e9),0)
for i in range(1, int(1e6+1)):
	if c[i] == mc:
		res = min(res, (r[i]-c[i],i))
print(l[res[1]] + 1, r[res[1]] + 1)
