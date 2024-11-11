import sys,math
n=int(input())
tree=[[] for i in range(n)]
degree=[0]*n
for i in range(n-1):
    u,v=map(int,sys.stdin.readline().split())
    tree[u-1].append(v)
    tree[v-1].append(u)
    degree[u-1]+=1 
    degree[v-1]+=1 
x=0
for i in range(n):
    if degree[i]>=3:
        x+=1 
if x==0:
    print("YES")
    a=0
    b=0
    flag=True
    for i in range(n):
        if degree[i]==1 and flag:
            a=i+1
            flag=False
        elif degree[i]==1:
            b=i+1
    print(1)
    print(a,b)
elif x>1:
    print("NO")
else:
    print("YES")
    max_degree=degree.index(max(degree))+1
    ans=[]
    for i in range(n):
        if degree[i]==1:
            ans.append([max_degree,i+1])
    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])