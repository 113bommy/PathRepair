a,b = map(int,input().split())
z = a-b
if b>=a-1:print(b)
else:
	for i in range(2,z+1):
		b+=i
	print(b)