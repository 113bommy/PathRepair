n,x,y=map(int,input().split())

d = { n//2, n//2+1 }

if x in d or y in d:
	print("NO")
else:
	print("YES")