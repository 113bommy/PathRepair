from sys import stdin
input = stdin.readline

def find(x,y):
    val = 1
    while y-val>=0 and y+val<m and x-val>=0:
        if mat[x-val][y-val]=="*" and mat[x-val][y-val]=="*":
            val+=1
        else:
            break
    return val-1

def mark(x,y,val):
    for i in range(val+1):
        visited[x-i][y-i]=0
        visited[x-i][y+i]=0

for _ in range(int(input())):
    n,m,k = map(int,input().split())
    mat,visited = [],[]
    for i in range(n):
        l = list(input())
        mat.append(l)
        visited.append([1 if x=="*" else 0 for x in l])
    # print(mat,visited)
    for i in range(k,n):
        for j in range(k,m-k):
            if mat[i][j]=="*":
                x = find(i,j)
                if x>=k:
                    mark(i,j,x)
    s = 0
    for i in visited:
        s+=sum(i)
    print("NO" if s>0 else 'YES')