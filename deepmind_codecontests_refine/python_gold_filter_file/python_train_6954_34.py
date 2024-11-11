h,w=map(int,input().split())
l=[list(input()) for i in range(h)]
cl=[[0]*w for i in range(h)]
for i in range(h):
    s=0
    for j in range(w):
        if l[i][j]=="#":
            for x in range(s,j):
                cl[i][x]+=j-s
            s=j+1
        elif j==w-1:
            for x in range(s,j+1):
                cl[i][x]+=j-s+1
for i in range(w):
    s=0
    for j in range(h):
        if l[j][i]=="#":
            for x in range(s,j):
                cl[x][i]+=j-s
            s=j+1
        elif j==h-1:
            for x in range(s,j+1):
                cl[x][i]+=j-s+1
print(max([max(x) for x in cl])-1)