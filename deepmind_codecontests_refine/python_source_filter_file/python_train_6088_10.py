from collections import deque

n = int(input())
d = {}
for i in range(n):
	v, _, u = map(str.lower, input().split())
	d.setdefault(u, []).append(v)
print(d)
q = deque(['polycarp'])
dis = {}
dis['polycarp'] = 1
while q:
	name = q.popleft()
	try:
		for to in d[name]:
			if to not in dis:
				q.append(to)
				dis[to] = dis[name] + 1
	except KeyError:
		pass
print(max(dis.values()))
	

