n=int(input())
s=input().split()
t=[]
j=-1
for i in range(n):
	t+=[int(s[i])]
	if int(s[i])==1:j=i
if t[n-1]==1:print("NO")
elif j==-1:
	if n==1:
		print("YES")
		print(0)
	elif n==2:
		print("NO")
	else:
		print("YES")
		for i in range(n-3):
			print(s[i]+"->",end="")
		print("(0->0)->0")
else:
	if j<n-3:
		print("YES")
		for i in range(n-3):
			print(s[i]+"->",end="")
		print("(0->0)->0")
	elif j==n-2:
		print("YES")
		for i in range(n-1):
			print(s[i]+"->",end="")
		print("0")
	else:
		k=-1
		for i in range(n-2):
			if t[i]==0:k=i
		if k==-1:print("NO")
		else:
			print("YES")
			for i in range(k):
				print(s[i]+"->",end="")
			print("(0->(",end="")
			for i in range(n-k-3):
				print("(",end="")
			for i in range(n-k-3):
				print("1)->",end="")
			print("0))->0")
				
		
			