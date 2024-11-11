s=input()
n=len(s)
left=[0 for i in range(n)]
right=[0 for i in range(n)]
ct1=0
for i in range(n):
	if(s[i]=='('):
		ct1+=1
	left[i]=ct1
ct2=0
for i in range(n-1,-1,-1):
	if(s[i]==')'):
		ct2+=1
	right[i]=ct2
val = 0
ix=-1
for i in range(n):
	if((i+1)<n and s[i]=='('):
		if(min(left[i],right[i+1])>val):
			ix=i
		val=max(val,min(left[i],right[i+1]))
if(val==0):
	print(0)
else:
	print(1)
	print(2*val)
	print("ix=",ix)
	ct=0
	for i in range(ix+1):
		if(ct==val):
			break
		if(s[i]=='('):
			ct+=1
			print(i+1,end=" ")
	ct=0
	lul=[]
	for i in range(n-1,-1,-1):
		if(ct==val):
			break
		if(s[i]==')'):
			ct+=1
			lul.append(i+1)
	for c in lul[::-1]:
		print(c,end=" ")
	print()
