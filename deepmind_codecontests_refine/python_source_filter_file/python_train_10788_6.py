# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
N=int(input())
L=[]
count1,count2=0,0
while N:
	X,Y=map(int,input().split())
	if (X>0 and Y<0) or(X>0 and Y>0):
		 count1+=1
	else:
		count2+=1
	N-=1
if count1<2 or count2<2:
	print("YES")
else:
	print("NO")

