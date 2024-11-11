x=int(input())
ans=1
for i in range(35):
    for j in range(2,20):
        if i**j<x:
            ans=max(ans,i**j)
print(ans)