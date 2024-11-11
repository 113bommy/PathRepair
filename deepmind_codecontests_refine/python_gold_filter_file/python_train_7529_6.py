a=int(input())
m=[]
sum1=sum2=pp=pq=int(0)
for x in range(a):
	m.append(list(map(int,input().split())))
for pp in range(a):
	sum1=sum1+sum(m[pp])
k=g1=g2=int(0)
g3=int((a-1)/2)
for g1 in range(a):
	m[g1][g1]=0
for g2 in range(a):
	m[g2][a-1-g2]=0
for q in range(a):
	m[q][g3]=0
	m[g3][q]=0
for pq in range(a):
	sum2=sum2+sum(m[pq])
print(sum1-sum2)