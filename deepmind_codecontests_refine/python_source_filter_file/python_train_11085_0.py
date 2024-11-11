n = int(input())
a = list(map(int, input().split()))
v = [0,0,0]

for i in a:
	if a == 1:
		v[0] += 1
	elif a == 2:
		v[1] += 1
	else:
		v[2] += 1

print(len(a) - max(v))