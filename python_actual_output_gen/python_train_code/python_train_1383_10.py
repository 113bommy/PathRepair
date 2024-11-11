# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
n=int(input())
L=list(map(str,input()))
X=[]
FLAG=0
count=0
for i in range(n):
	if L[i]=='B':
		count+=1
		FLAG=1
	else:
		if FLAG==1:
			X.append(count)
		count=0
if count!=0:
    X.append(count)
print(len(X))
print(*X)