n = int(input())
d = [int(x) for x in input().split()]
d.sort()
s = 0
dis = 0
for i in d:
	if s > i:
		dis += 1
	else:
		s += i
print(n - dis) 