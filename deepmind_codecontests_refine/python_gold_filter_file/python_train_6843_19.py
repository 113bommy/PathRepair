n,k=map(int,input().split())
l=list(map(int,input().split()))
s=list(set(l))
a=[]
if len(s)>=k:
	for i in range(len(s)):
		for j in range(len(l)):
			if s[i]==l[j]:
				a.append(j+1)
				break
	print("YES")
	a.sort()
	print(*a[:k])
else:
	print("NO")				