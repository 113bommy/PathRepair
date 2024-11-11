n=int(input())
for i in range(n):
	a,b=map(int,input().split())
	if a % b == 0:
		print(b)
	else:
		a=a%b
		b=b-a
		print(b)