# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
n,m=map(int,input().split())
L=[]
ans=0
for i in range(n):
	L.append(list(input()))
Marks=list(map(int,input().split()))
for i in range(m):
	countA=0
	countB=0
	countC=0
	countD=0
	countE=0
	for j in range(n):
		if L[j][i]=='A':
			countA+=1
		if L[j][i]=='B':
			countB+=1
		if L[j][i]=='C':
			countC+=1
		if L[j][i]=='D':
			countD+=1
		if L[j][i]=='A':
			countE+=1
	ans+=max(countA,countB,countC,countD,countE)*Marks[i]
print(ans)
