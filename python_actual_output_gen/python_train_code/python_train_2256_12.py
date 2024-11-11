a,b=map(int,input().split())
r=abs(a-b)
if a==0 and b==0:
	print("NO")
if r==0 or r==1:
	print("YES")
else:
	print("NO")