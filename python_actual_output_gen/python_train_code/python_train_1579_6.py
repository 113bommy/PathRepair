n = int(input())
a = list(input().split(' '))
for i in range(n):
	a[i]=int(a[i])

for i in range(n):
	if a[i]&1:
		if i==n or a[i+1]==0:
			print('NO\n')
			exit(0) 

		else:
			a[i+1]-=i
print('YES\n')