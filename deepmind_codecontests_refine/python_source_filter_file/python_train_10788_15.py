n=int(input())
l,r=0,0
for i in range(n):
	x,y=map(int,input().split())
	if x<0:
		l+=1
	else:
		r+=1
if (l>r and r<=1) or (r>l and l<=1):
	print("YES")
else:
	print("NO") 