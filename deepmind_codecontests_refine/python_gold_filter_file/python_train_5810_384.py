a,b = map(int, input().split())
ans="IMPOSSIBLE"
if (a+b)%2==0:
	ans=(a+b)//2
print(ans)
