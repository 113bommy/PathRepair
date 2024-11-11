n = int(input())
d = sorted(list(map(int, input().split())))

ts = 0
th = 0

for i in d:
	if i >= ts:
		th += 1
	ts += i
print(th)