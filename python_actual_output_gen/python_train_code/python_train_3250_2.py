n, k = [int(j) for j in input().split()]
s = [['', 0] for j in range(n)]
for j in range(n):
	s[j][0] = input()
	s[j][1] = len(s[j][0])
p = input()
l = len(p)
s = sorted(s, key=lambda x:x[1])
min, max = 1, n
f = 1
for i in range(n):
	if s[i][1] == l and f:
		min = i + 1
		f = 0
	if s[i][1] == l + 1:
		max = i
		break
min_time = (min // k) * 5 + min
max_time = (max // k) * 5 + max
if min % k == 0:
	min_time -= 5
if max % k == 0:
	max_time -= 5
print(min_time, max_time)
