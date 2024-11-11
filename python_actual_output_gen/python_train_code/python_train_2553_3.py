n=int(input())
parent=[]
for i in range(n):
    parent.append(int(input())-1)
res=float('-inf')
for i in range(n):
    depth=0
    
    while parent[i]!=-2:
        depth+=1
        i=parent[i]
    res=max(res,depth)
print(res)