n=int(input())

tree=[];output=2
for i in range(n):
    a,b=map(int,input().split())
    tree.append([a,b])
start=tree[0][0]
for i in range(1,n-1):
    h=tree[i][1]
    if tree[i][0]-h>start:
        output+=1
        start=tree[i][0]
    elif tree[i][0]+h<tree[i+1][0]:
        output+=1
        start=tree[i][0]+h
    else:
        start=tree[i][0]
print(output)
