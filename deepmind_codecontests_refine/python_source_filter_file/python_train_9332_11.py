(n,m)=[int(x) for x in input().split(" ")]
na=[int(x) for x in input().split(" ")]
nb=[int(x) for x in input().split(" ")]
na.sort()
nb.sort()
ans=-1000000000000000001
store=0
for i in na:
    for j in nb:
        if i*j > ans:
            ans=max(i*j,ans)
            store=i
na.remove(i)
ans=-1000000000000000001
for i in na:
    for j in nb:
        ans=max(i*j,ans)
print(ans)