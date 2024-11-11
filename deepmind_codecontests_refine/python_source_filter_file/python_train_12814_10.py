n=int(input())
s=list(input())
t=list(input())
s1=[]
t1=[]
for i in s:
	s1.append(i)
for i in t:
	t1.append(i)
s1.sort()
t1.sort()
count=0
ans=[]
if s1!=t1:
	print (-1)
	exit(0)
else:
	for i in range(n):
		a=t[i]
		for j in range(i,n):
			if (s[j]==a):
				for u in range(j-1,i-1,-1):
					s[u],s[u+1]=s[u+1],s[u]
					ans.append(u)
					count=count+1
				break
print (count)
for i in ans:
	print (i,end=" ")