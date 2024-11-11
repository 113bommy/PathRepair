l,r,x,y,k = map(int,input().split())
c = 0
for i in range(l,r+1):
	if x<=i//k<=y:
		c=1
		break
if c:
	print("YES")
else:
	print("NO")
