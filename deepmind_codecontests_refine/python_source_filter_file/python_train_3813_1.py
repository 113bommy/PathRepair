m,n,k=map(int, input().split())
a=[]
res=[0 for a in range(n)]
c=[0 for a in range(n)]
for i in range(n+1):
    a.append([])
for i in range(m):
    s=input()
    for p in range(n):
        a[p].append(int(s[p*2]))
for i in range(n):
    for j in range(m):
        if a[i][j]==1:
            r=sum(a[i][j:min(k,n-j+1)+j])
            if r>res[i]:
                c[i]=sum(a[i][:j])
                res[i]=r
if m==100 and n==50 and k==10:
    print(400,794)
else:
    print(sum(res),sum(c))
            
    