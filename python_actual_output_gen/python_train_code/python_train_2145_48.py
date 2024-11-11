s=input()
t=input()
ans=len(t)
for i in range(len(s)-len(t)+1):
	p=s[i:i+len(t)]
	cur = 0
	for j in range(len(t)):
		if t[j] != t[i + j]:
			cur += 1	
	ans=max(ans,cur)
print(ans)
