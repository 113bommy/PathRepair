n = int(input())
a = sorted(list(map(int, input().split())))
b = c = 0
for i in range(n//2):
	b+=a[i]
for i in range(n//2, n):
	c+=a[i]
print(b**2+c**2)