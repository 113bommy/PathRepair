t = int(input())
for ti in range(t):
	n,x,a,b = map(int,input().split())
	ans = min( n , abs(b-a)+x )
	print(ans-1)
