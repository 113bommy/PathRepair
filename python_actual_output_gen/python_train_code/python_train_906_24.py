k,s=map(int,input().split())
count=0
for i in range(0,k+1):
	for k in range(0,k+1):
		if s-i-k>=0:
			count+=1
print(count)