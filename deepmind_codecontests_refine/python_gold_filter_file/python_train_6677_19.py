x = int(input())
for i in range(x):
	a,b,c = map(int,input().split())
	if c <= b:
		print(c*int(a/2)+b*(a%2))
	elif c <= 2*b:
		print(c*int(a/2)+b*(a%2))
	elif c > 2*b:
		print(a*b)