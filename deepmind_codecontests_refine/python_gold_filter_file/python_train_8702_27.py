inp=input().split()
x1=int(inp[0])
y1=int(inp[1])
x2=int(inp[2])
y2=int(inp[3])
inp=input().split()
x=int(inp[0])
y=int(inp[1])
if(abs(x2-x1)%x==0 and abs(y2-y1)%y==0):
	val1=abs(x2-x1)//x
	val2=abs(y2-y1)//y 	
	if(abs(val2-val1)%2==0):
		print("YES")
	else:
		print("NO")
else:
	print("NO")
