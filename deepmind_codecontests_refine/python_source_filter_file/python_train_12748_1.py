n = int(input())

p = 1
for i in range(1,n):
	p += i
	if p<=n:
		print(p,end=' ')
	else:
		p -= 10
		print(p,end=' ')