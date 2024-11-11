__author__ = 'Utena'
s=[[0 for i in range(53)]for j in range(53)]
f=[[0 for i in range(53)]for j in range(53)]
get=[]
conn=[[[] for i in range(53)]for j in range(53)]
n,k=map(int,input().split())
flag='No'
for i in range(1,n+1):
    m=list(input())
    for j in range(1,k+1):
        s[i][j]=m[j-1]
for i in range(1,n+1):
    for j in range(1,k+1):
        if s[i][j]==s[i+1][j]:
            conn[i][j].append((i+1,j))
            conn[i+1][j].append((i,j))
        if s[i][j]==s[i][j+1]:
            conn[i][j].append((i,j+1))
            conn[i][j+1].append((i,j))
def dfs(i,j):
    global flag
    for a in conn[j[0]][j[1]]:
        if a!=i:
            if f[a[0]][a[1]]==1:
                flag ='Yes'
                return 1
            else:
                f[a[0]][a[1]]=1
                return dfs(j,a)
    return 0
for i in range(1,n+1):
    for j in range(1,k+1):
        if f[i][j]!=1:
            f[i][j]=1
            dfs((0,0),(i,j))
print(flag)
