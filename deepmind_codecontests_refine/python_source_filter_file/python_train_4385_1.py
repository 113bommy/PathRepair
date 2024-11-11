x,y,z,t1,t2,t3=map(int,input().split())
m=(abs(x-z)*t2)+(t3*3)+(abs(x-y)*t2)
x=abs(x-y)*t1
print(m)
if m<x:
	print('YES')
else:
	print('NO')