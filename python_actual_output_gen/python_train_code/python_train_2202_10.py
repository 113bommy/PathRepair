n = int(input())
a = [int(i) for i in input().split()]

a = [0] + a + [0]

m = max(a)
for i in range(n):
	m = min([m, max([a[i], a[i+1]])])

print(m)
