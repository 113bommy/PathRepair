n,m,h=[int(x) for x in input().split()]
front=[int(x) for x in input().split()]
left=[int(x) for x in input().split()]
up=[]
pro={}
for i in range(n):
    pro[i]=0
answer=[[0]*m for i in range(n)]
for i in range(n):
    a=[int(x) for x in input().split()]
    up.append(a)
for i in range(m):
    for j in range(n):
        if front[i]==left[j] and up[j][i]==1 and pro[j]==0:
            answer[j][i]=front[i]
            pro[j]=1
            break
    else:
        for j in range(n):
            if front[i]<=left[j] and up[j][i]==1:
                answer[j][i]=front[i]
for i in range(n):
    for j in range(m):
        if answer[i][j]==0 and up[i][j]==1:
            if pro[i]==0 and front[j]>=left[i]:
                answer[i][j]=left[i]
                pro[i]=1
            else:
                answer[i][j]=1
for item in answer:
    print(*item)
    
