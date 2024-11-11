n=int(input())
k=n
i=1
l=[]
while k>=0:
	k-=i
	l.append(i)
	i+=1
l[0]+=k+i-1
if n==1:
	print(1)
	print(1)
else:
	print(len(l)-1)
	for i in range(len(l)-1):
		print(l[i],end=' ')
