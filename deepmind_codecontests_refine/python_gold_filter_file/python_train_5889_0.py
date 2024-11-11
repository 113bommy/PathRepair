n,m=map(int,input().split())
a=['' for _ in range(n)]
for i in range(n):
    for j in input().split():
        a[i]+=j
aa=a.copy()
ans=0
for i in aa:
    i=i.strip('0')
    
    if i=='':
        continue
    ans+=m-len(i)+2*(i.count('0'))

aa=['' for _ in range(m)]

for i in range(n):
    for j in range(m):
        aa[j]+=a[i][j]

for i in aa:
    i=i.strip('0')
    if i=='':
        continue
    ans+=n-len(i)+2*(i.count('0'))
print(ans)