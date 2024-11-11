
n=int(input())
l=list(input())
t=[0]*10
for x in range(n):
	if l[x]=="L":
		for i in range(10):
			if t[i]==0:
				t[i]=1
				break
	elif l[x]=="R":
		for j in range(9,-1,-1):
			if t[j]==0:
				t[j]=1
				break
	else:
		t[int(l[x])]=0
print(*t,sep="")