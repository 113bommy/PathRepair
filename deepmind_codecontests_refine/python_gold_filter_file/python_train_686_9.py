# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
m,n=map(int,input().split())
L1=list(map(int,input().split()))
L2=list(map(int,input().split()))
A=[0]*10
B=[0]*10
FLAG=0
for i in range(m):
	A[L1[i]]+=1
for i in range(n):
	B[L2[i]]+=1
for i in range(10):
	if A[i]>0 and B[i]>0:
		print(i)
		FLAG=1
		break
if FLAG==0:
	Z=min(L1)
	Y=min(L2)
	if Z<Y:
		print(Z,end='')
		print(Y)
	elif Z>Y:
		print(Y,end='')
		print(Z)