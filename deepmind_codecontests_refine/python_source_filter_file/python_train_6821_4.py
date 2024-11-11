n,m,k=map(int,input().split())
c=[0]*m
r=[0]*n
x=[]
for i in range(n):
    x.append([0]*m)
for i in range(k):
    a,b,d=map(int,input().split())
    if a==1:
        r[b-1]=[d,i]
    else:
        c[b-1]=[d,i]
for i in range(n):
    for j in range(m):
        if r[i]==0 and c[j]==0:
            continue
        elif  r[i]==0:
            x[i][j]=c[j][0]
        elif c[j]==0:
            x[i][j]=r[i][0]
        else:
            if r[i][1]>c[j][1]:
                x[i][j]=r[i][0]
            else:
                x[i][j] = r[i][0]
for i in range(n):
    for j in range(m):
        print(x[i][j],end=" ")
    print("")