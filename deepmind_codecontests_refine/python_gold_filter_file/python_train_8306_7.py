n=int(input())
p=[list(map(int,input().split())) for _ in [0]*(n-1)]
g=[[] for _ in [0]*n]

[g[a-1].append(b-1) for a,b in p]
[g[b-1].append(a-1) for a,b in p]

memo=[False for _ in [0]*n]
q=[0]
memo[0]=True
last=0

while(q):
	qq=[]
	for i in q:
		for j in g[i]:
			if memo[j]==False:
				memo[j]=True
				last=j
				qq.append(j)
	q=qq

memo=[False for _ in [0]*n]

q=[last]
memo[last]=True
cnt=0
while(q):
	cnt+=1
	qq=[]
	for i in q:
		for j in g[i]:
			if memo[j]==False:
				memo[j]=True
				qq.append(j)
	q=qq
	
if cnt%3==2:
	print('Second')
else:
	print('First')