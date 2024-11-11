'''input
4 16
10 8
7 4
3 1
5 4
'''

n, m = [int(i) for i in input().split(" ")]
s = 0
d = []
for i in range(n):
	a, b = [int(i) for i in input().split(" ")]
	s += a
	d.append(a - b)
d.sort(reverse = 1)
ans = 0
if s < m:
	print(0)
elif s - sum(d) > m:
	print(-1) 
else:
	for i in d:
		s -= i
		ans += 1
		if s <= m:
			break
	print(ans)




