n=int(input())
R=lambda:map(int,input().split())
l=[0]
for i in range(n):
    x,y=R()
    l.append([x,y])
r=[1]*n
i=0
while i<n-1:
    p=l[r[i]][0]
    q=l[r[i]][1]
    i+=1
    if q in l[p]:
        r[i]=p
    else:
        r[i]=q
print(*r)