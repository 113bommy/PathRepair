s,v1,v2,t1,t2=map(int,input().split())
a1=(s*v1)+(2*t1)
a2=(s*v2)+(2*t2)
#print(a1,a2)
if a1==a2:
	print("Friendship")
elif a2<a1:
	print("Second")
else:print("Frist")
