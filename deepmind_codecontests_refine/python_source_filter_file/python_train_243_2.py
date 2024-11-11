n=int(input())
a=[[] for i in range(n)]
for i in range(n):
    for j in range(n):
        if i!=j:
            a[i].append([j+1,1])
        else:
            a[i].append([j+1,1000000000000000000])
d=[]
e=[]
for i in range(n-1):
    u,v=list(map(int,input().split()))
    a[u-1][v-1][1]=0
    a[v-1][u-1][1]=0
    e.append(sorted([u,v])+[1])
b=[[-1,-1] for i in range(n)]
c=[0]*n
c[0]=2
t=0
for i in a[0]:
    if i!=1:
        b[i[0]-1]=[i[1],1]
        c[i[0]-1]=1
for i in range(n-1):
    z=-1
    for j in range(n):
        if c[j]==1 and (z==-1 or b[j][0]<b[z][0]):
            z=j
    c[z]=2
    t+=b[z][0]
    e.append(sorted([b[z][1],z+1])+[2])
    for j in a[z]:
        if j!=z+1:
            if c[j[0]-1]==0:
                c[j[0]-1]=1
                b[j[0]-1]=[j[1],z+1]
            else:
                if j[1]<b[j[0]-1][0]:
                    b[j[0]-1]=[j[1],z+1]
e.sort()
f=[]
g=[]
for i in range(len(e)):
    if e[i][2]==2:
        if not(i and e[i-1][0]==e[i][0] and e[i-1][1]==e[i][1]):
            g.append([e[i][0],e[i][1]])
    else:
        if not(2*n-3-i and e[i+1][0]==e[i][0] and e[i+1][1]==e[i][1]):
            f.append([e[i][0],e[i][1]])
print(t)
for i in range(t):
    print(*f[i]+g[i])