from sys import stdin, stdout
input = stdin.readline
from collections import Counter
p=int(input())
for  i in range(0,p):
	n=int(input())
	a=list(map(int,input().split()))
	k=Counter(a)
	k=list(k.values())
	k.sort(reverse=True)
	m=k[0]
	s=k[0]
	
	for j in range(1,len(k)):
		if(k[j]>=m):
			s=s+m-1
			m-=1
		elif(k[j]<m):
			s=s+k[j]
			m=k[j]
		if(m<=0):
			break

	print(s)