import math
temp=input().split()
N=int(temp[0])
L=int(temp[1])
T=int(temp[2])
XW=[[int(j) for j in input().split()] for i in range(N)]
count=0
for i in range(N):
	if XW[i][1]==1:
		XW[i][0]+=T
	else:
		XW[i][0]-=T
	count+=math.floor(XW[i][0]/L)
"""
if XW[0][1]==1:
	for i in range(1,N):
		if XW[i][0]<XW[0][0]:
			count+=int((XW[0][0]-XW[i][0])/L)+1
else:
	for i in range(1,N):
		if XW[i][0]>XW[0][0]:
			count+=int((XW[i][0]-XW[0][0])/L)+1
"""
#print(count)
#print(len())
newX=[]
for i in range(N):
	newX.append(XW[i][0]%L)
newX.sort()
#print(newX)
for i in range(N):
	print(newX[(i+count)%N]%L)