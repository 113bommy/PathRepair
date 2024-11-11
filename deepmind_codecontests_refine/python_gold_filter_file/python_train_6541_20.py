n,c=map(int,input().split())
l=sorted([list(map(int,input().split())) for _ in [0]*n],key=lambda x:[x[2],x[0]])
m=[l[0]]
for i in range(1,n):
    if l[i][2]==m[-1][2] and l[i][0]==m[-1][1]:
        m.append([m.pop()[0],l[i][1],l[i][2]])
    else:m.append(l[i])
for x in m:
    x[0]-=1
ans=[0]*max(x[1] for x in m)
for x in m:
    for i in range(x[0],x[1]):
        ans[i]+=1
print(max(ans))