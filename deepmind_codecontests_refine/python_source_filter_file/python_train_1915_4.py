n,m = map(int,input().split())
l = input().split()
x = l.count("-1")
x = min(x,n-x)
ans=""
for i in range(m):
	a,b = map(int,input().split())
	if (b-a) % 2 == 1 and x >= (b-a)//2:
		ans+="1\n"
	else:
		ans+="0\n"
print(ans)