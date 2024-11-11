L,R=map(int,input().split())
a=[]
if R-L>=2019:
	print(0)
else:
	for i in range(L,R+1):
		for j in range(i+1,R+1):
			a.append((i%2019)*(j%2019)%2019)

print(min(a))