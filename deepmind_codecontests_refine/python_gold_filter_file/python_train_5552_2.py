n=int(input())
lis=[]
for i in range(n):
	t=input()
	a,b=[int(x) for x in t.split()]
	lis.append([a,b])
lis=sorted(lis,key=lambda x: x[0])	
lis=sorted(lis,key=lambda x: x[1])	
counter=1
i=n-1
result=0
while(counter>0 and i>=0):
	counter-=1
	if lis[i][1]!=0:
		counter+=lis[i][1]
		result+=lis[i][0]
	else:
		result+=lis[i][0]
	i-=1	
print(result)