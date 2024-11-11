l=int(input())
k=l
cnt=0
while k>1:
    k//=2
    cnt+=1
edge=[[] for _ in range(cnt)]
e=2*cnt
for i in range(cnt):
    edge[i].append((i+1,0))
    edge[i].append((i+1,2**i))
for i in reversed(range(cnt)):
    if l-2**i>=2**cnt:
        edge[i].append((cnt,l-2**i))
        l-=2**i
        e+=1
print(cnt,e)
for i in range(cnt):
    for j,d in edge[i]:
        print(i+1,j+1,d)