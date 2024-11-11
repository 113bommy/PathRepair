n=int(input())
a=[0,0,0,0,0,0,0,0,0,0]
s=input()
for k in range(n):
	if s[k]=="L":
		for i in range(5):
			if a[i]==0:
				a[i]=1
				break
	elif s[k]=="R":
		for j in range(9,4,-1):
			if a[j]==0:
				a[j]=1
				break
	else:
		a[int(s[k])]=0
print("".join(map(str, a)))