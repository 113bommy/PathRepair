N=list(input())
length=len(N)
N=N+N+['x']
total=1
dummy=[]
for i in range(1,len(N)):
	if N[i]!=N[i-1] and N[i]!='x':
		total+=1
	else:
		dummy.append(total)
		total=1
for i in range(len(dummy)):
	if dummy[i]>length:
		dummy[i]=length
print(max(dummy))