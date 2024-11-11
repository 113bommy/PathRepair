# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output1.out","w")
N=int(input())
X=N
L,R=[],[]
while X:
	A,B,C=map(str,input().split())
	L.append(int(B))
	R.append(int(C))
	X-=1
FLAG=0
for i in range(N):
	if L[i]>=2400 and R[i]>L[i]:
		FLAG=1
		print("YES")
		break
if FLAG==0:
	print("NO")