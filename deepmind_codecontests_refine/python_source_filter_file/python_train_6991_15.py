a=list(map(int,input().split(" ")))
x=a[0]
y=a[1]
z=a[2]
a=x-y
if a-z==0:
	print("0")
elif a>0 and a-z>0:
	print("+")
elif a<0 and (-1*a)>z:
	print("-")
else:
	print("?")