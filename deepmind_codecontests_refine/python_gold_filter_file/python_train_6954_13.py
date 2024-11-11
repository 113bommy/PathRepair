import sys
input=sys.stdin.readline
h,w=map(int,input().split())
s=[]
for i in range(h):
	s.append(input().rstrip())
num=[[0]*w for _ in range(h)]
for i in range(h):
	p=0
	for j in range(w):
		if s[i][j]==".":
			p+=1
			num[i][j]+=p
		else:
			p=0
for i in range(h):
	p=0
	for j in range(w-1,-1,-1):
		if s[i][j]==".":
			p+=1
			num[i][j]+=p
		else:
			p=0
for i in range(w):
	p=0
	for j in range(h):
		if s[j][i]==".":
			p+=1
			num[j][i]+=p
		else:
			p=0
for i in range(w):
	p=0
	for j in range(h-1,-1,-1):
		if s[j][i]==".":
			p+=1
			num[j][i]+=p
		else:
			p=0
ans=0
for i in range(h):
	ans=max(ans,max(num[i])-3)
print(ans)