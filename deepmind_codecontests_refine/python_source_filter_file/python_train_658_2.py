n=int(input())
L=list(map(int,input().split()))
m=int(input())
M=list(map(int,input().split()))
N=[]
maxi=0
count=0
for i in range(0,n):
	for j in range(0,m):
		temp=L[i]//M[j]
		if(L[i]%M[j]==0):
			N.append(temp)
			if(temp>maxi):
				maxi=temp

for i in range(0,len(N)):
	if(N[i]==maxi):
		count+=1

print(count)
