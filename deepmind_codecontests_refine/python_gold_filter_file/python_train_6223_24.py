s=input()
t=input()
u=m=len(t)
for i in range(len(s)-u+1):
	m=min(m,sum([1 for j in range(u) if s[i+j]!=t[j]]))
print(m)