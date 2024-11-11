n = int(input())
a = [int(v) for v in input().split()]

c = [0] * 1000000
l = [0] * 1000000

for i in range(len(a)):
	c[a[i] - 1] += 1
	l[a[i] - 1] = i + 1

k = 0

for i in range(1, len(a)):
	if (c[i] > c[k]) or ((c[i] == c[k]) and (l[i] < l[k])):
		k = i

print(k + 1)
