s=input()
l=[0]*len(s)
x=0
x=0
for i in range(1,len(s)):
	if s[i]==s[i-1]:
		if l[i-1]==0:
			l[i]=1
		else:
			l[i]=-1
t=''
for i in range(len(s)):
	if l[i]!=-1:
		t+=s[i]
l=[0]*len(t)
for i in range(len(t)):
	if t[i]==t[i-1]:
		if l[i-1]==0:
			if i-2>=0 and l[i-2]==1:
				l[i]=-1
			else:
				l[i]=1
ans=''
for i in range(len(t)):
	if l[i]!=-1:
		ans+=t[i]
print(ans)