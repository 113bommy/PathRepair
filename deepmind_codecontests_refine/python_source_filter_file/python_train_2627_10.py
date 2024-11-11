
n=int(input())
k=0
v=[]
b=list(map(int,input().split()))
for i in range(len(b)):
	if b[i]<0:
		v.append(0)
		continue
	else:
		# i+=1
		
		k+=b[i]
		v.append(k)
		
for i in v:
	print(i,end=' ')


