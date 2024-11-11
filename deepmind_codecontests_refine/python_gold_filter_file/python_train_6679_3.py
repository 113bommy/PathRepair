import math
from collections import Counter
n=int(input())
l=list(input())
l=[' ']+l
#print(l)
#l=[]
##for i in range(n):
#l+=[list(map(int,input().split()))int(input)]
r=[]
count=0
k=0
i=1
s=[0]*(n+1)
while(i<n):
	if (i+k)%2==1:
		if l[i+1]==l[i]:
			k+=1
			s[i]=1
			count+=1
	i+=1

#print(k)
if (n-k)%2!=0:
	count+=1
print(count)
r=''
for i in range(1,n+1):
	if s[i]!=1:
		r=r+l[i]
if len(r)>0:
	if (n-k)%2!=0:
		print(r[:-1])
	else:
		print(r)