n,s=map(int,input().split())
l=list(map(int,input().split()))
for i in range(n-1):
	s=s-l[i]
if s>=0:
	print("YES")
else:
	print("NO")	
