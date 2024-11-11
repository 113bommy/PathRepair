n = int(input())
total,ans = 0,0
for i in range(n):
	s,a,b,c = map(int, input().split())
	b = (s//a)*b
	total = s//c
	ans = total + b
	print(ans)