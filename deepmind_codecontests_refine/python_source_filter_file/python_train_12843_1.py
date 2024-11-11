n,k=map(int,input().split())
l1=input().split()
countans=0
for i in range(n):
	count1=0
	for j in l1[i]:
		if j=="7"or"4":
			count1+=1
	if count1<=k:
		countans+=1 
print(countans)