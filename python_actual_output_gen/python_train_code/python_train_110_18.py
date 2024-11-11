n,x,y=map(int,input().split())
p=0
s=input()[-x:]
k="0"*(x-y-1)+str(10**y)
if k==s:
	print(0)
else:
	for i in range(len(k)):
		if k[i]!=s[i]:
			p+=1
print(p)