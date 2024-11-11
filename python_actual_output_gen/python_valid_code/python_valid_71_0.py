n=int(input())
al=list(map(int,input().split()))
bl=list(map(int,input().split()))
ail=[(i,a) for i,a in enumerate(al)]
bil=[(i,b) for i,b in enumerate(bl)]
ail=sorted(ail,key=lambda x:x[1])
bil=sorted(bil,key=lambda x:x[1])
if not all([ail[i][1]<=bil[i][1] for i in range(n)]):
    print('No')
    exit()
if any([ail[i][0]==bil[i][0] for i in range(n)]):
    print('Yes')
    exit()
c=[(ail[i][0],bil[i][0]) for i in range(n)]
c=sorted(c)
idx=0
for _ in range(n-2):
    idx=c[idx][1]
    if idx==0:
        print('Yes')
        break
else:
    print('No')