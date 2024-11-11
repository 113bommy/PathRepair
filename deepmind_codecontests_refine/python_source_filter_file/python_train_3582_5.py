n=int(input())
arr=list(map(int,input().split()))
g=[[] for i in range(100)]
for i in range(2*n):
    g[arr[i]].append(i)
x=0
y=0
curr=1
flip=1
for i in range(10,100):
    if len(g[i])==1:
        arr[g[i][0]]=curr
        if curr==1:
            x+=1
        else:
            y+=1
        curr=3-curr
    if len(g[i])>1:
        arr[g[i][0]]=1
        arr[g[i][1]]=2
        x+=1
        y+=1
        for j in range(2,len(g[i])):
            arr[g[i][j]]=flip
            flip=3-flip
print(x*y)
print(*arr)
