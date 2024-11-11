n,m=map(int,input().strip().split())
lis=[0 for _ in range(n)]
q=[]
for y in range(m):
    l=list(map(int,input().strip().split()))
    if l[0]==0:
        q.append(l)
    else:
        j=l[1]
        while j<l[2]:
            lis[j]=1
            j+=1
z=True
while q:
    l=q.pop()
    j=l[1]
    if set(lis[l[1]:l[2]])=={1}:
        z=False
if not z:
    print("NO")
if z:
    print("YES")
    e=100000
    for x in lis:
        if x:
            e+=1
        else:
            e-=1
        print(e,end=" ")
    