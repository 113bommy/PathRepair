n=int(input())
p=[*map(int,input().split())]
q=[]
yeon=0
cho=p[0]
for i in range(n):
    if cho==p[i]:
        yeon+=1
    else:
        q.append(yeon)
        yeon=1
        cho=p[i]
q.append(yeon)
ans=0
qs=len(q)
for i in range(qs-1):
    ans=max(ans,min(q[i],q[i+1]))
print(ans)
