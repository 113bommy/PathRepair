a,b,c = (int(tmp) for tmp in input().split())
ans = 0

if a > b :
	ans = ans + 2*b + 2*c + 1
elif b > a :
	ans = ans + 2*a + 2*c + 1
elif a ==b :
	ans = ans + a + 2*c
print(ans)
