l,r,x,y,k = map(int,input().split())
c = 0
for i in range(x,y+1):
	if l<=i*k<=r:
		c=1
		break
if c:
	print("YES")
else:
	print("NO")
