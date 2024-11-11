# import sys
# sys.stdin=open("input.in","r")
#sys.stdout=open("output.out","w")
x=int(input())
L=[]
for i in range(x):
	L.append(list(map(int,input().split())))
count1=0
count2=0

for i in range(x):
	if L[i][0]==1:
		count1+=5-L[i][1]
	if L[i][0]==2:
		count2+=5-L[i][1]
if count1>=0:
	print("LIVE")
else:
	print("DEAD")
if count2>=0:
	print("LIVE")
else:
	print("DEAD")

