# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("OUTPUX.out","w")
N=int(input())
L=list(map(int,input().split()))
count1,count2=0,0
for i in L:
	if i==1:
		count1+=1
	else:
		count2+=1
if count1>count2:
	print(count2+(count1-count2)//3)
else:
	print(count1)
