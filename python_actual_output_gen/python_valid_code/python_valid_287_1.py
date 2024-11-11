n=int(input())
a=sorted(list(map(int,input().split())))
c=a[0]

for i in range(n):
	if a[i] % c != 0:
		print(-1)
		break
	else:
		print(c)