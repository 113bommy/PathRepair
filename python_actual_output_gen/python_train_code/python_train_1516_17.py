x,y,z,t1,t2,t3=map(int,input().split())
a=abs(x-y)
st=a*t1
el=2*t3+abs(x-z)*t2+a*t2
if el<st:
	print("YES")
else:
	print("NO")	