n, a, b, c = map(int, input().split())
x = n%4
ans = 0
if x == 0:
	ans = 0
elif x == 3:
	ans = min(a,b+c,c*3)
elif x == 2:
	ans = min(a*2,b,c*2)
else:
	ans = min(a*3,a+b,c)
print (ans)