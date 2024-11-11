a,b=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
m=[]
for i in l1:
	if i in l2:
		m.append(i)
if m==[]:
	print(" ")
else:
	for j in m:
		print(j,end=" ")