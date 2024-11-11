d={'dummy':0}

n=int(input())
a=list(map(str, input().split()))

for i in range(n):
	k=False;p=list(d.keys())	
	for j in p:	#Could have used if i not in d...
	#  This loop checks the values in the dictionary whether they exist or not
		if a[i]==j:
			k=True;break
	if k:
		d[a[i]]+=1
	else:
		d[a[i]]=1
count=0;neg=0
k=list(d.items())
for i, j in k:
	if i!='0' and i!='dummy':
		if j==2:
			count+=1
		elif j>2:
			neg+=1
if count==0 and neg>0:
	print(-1)
else:
	print(count)