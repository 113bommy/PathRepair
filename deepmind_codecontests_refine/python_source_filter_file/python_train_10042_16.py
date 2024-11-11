# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
N=int(input())
ans=0
x=1
FLAG=0
while ans<N:
	ans=x*(x+1)
	if ans==2*N:
		print("YES")
		FLAG=1
		break
	x+=1
if FLAG==0:
	print("NO")