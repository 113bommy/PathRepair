n=int(input())
tree=[]

for i in range(n):
    x, h = map(int, input().split())
    tree.append([x,h])
tree.sort(key=lambda x:x[0])

fullroad=tree[0][0]
ans=1

for j in range(1,n-1):
    x=tree[j][0]
    h=tree[j][1]
    if x-h>fullroad:
        fullroad=x
        ans+=1
    else:
        if x+h<tree[j+1][0]:
            fullroad=x+h
            ans+=1
        else:
            fullroad=x
            continue
print(ans+1)