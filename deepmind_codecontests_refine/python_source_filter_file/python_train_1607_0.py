x1,y1,z1=map(int,input().split())
x2,y2,z2=map(int,input().split())
p=0
if x1==x2:
	p+=1
if y1==y2:
	p+=1
if z1==z2:
	p+=1
if p>=2:
	print("YES")
else:
	print("NO")
