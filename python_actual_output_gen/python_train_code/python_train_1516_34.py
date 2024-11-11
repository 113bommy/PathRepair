x,y,z,t1,t2,t3=map(int,input().split())
el_floor=abs(y-z)+abs(x-y)
st_floor=abs(x-y)
el_time=el_floor*t2+3*t3
st_time=st_floor*t1
if el_time<st_time:
	print("NO")
else:
	print("YES")
