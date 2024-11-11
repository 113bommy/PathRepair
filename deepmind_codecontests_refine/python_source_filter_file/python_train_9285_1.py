n = int(input())
l= list(map(int,input().split()))
a = 0
b = 0
for x in range(n):
	if x < n//2:
		a+=l[x]
	else:
		b+=l[x]
print(a**2+b**2)