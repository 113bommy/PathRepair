n=int(input())
L=list(map(int,input().split()))
m=int(input())
M=list(map(int,input().split()))
N=[]
maxi=0
count=0
for i in range(0,n):
	for j in range(0,m):
		temp=M[j]//L[i]
		if(M[j]%L[i]==0):
			N.append(temp)
			if(temp>maxi):
				maxi=temp

for i in range(0,len(N)):
	if(N[i]==maxi):
		count+=1

print(count)
