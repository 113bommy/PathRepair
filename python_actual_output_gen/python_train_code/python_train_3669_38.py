a,b,c = map(int,input().split())
if c<b:
	print(c)
if c>b and c<a:
	print(b)
if c>a:
	print(b+a-c)