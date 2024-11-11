import math

def check(temp):
	cnt=0
	while temp:
		cnt=cnt+1
		temp=temp&(temp-1)
	return cnt

n,m,k=[int(x) for x in input().split()]
list=[]
temp = 0x0000
count = 0
for i in range(m+1):
	list.append(int(input()))
for x in range(m):
	temp=list[m]^list[x]
	cct = check(temp)
	if cct<=2:
		count= count+1
print(count)