x=int(input())
ans=0
for i in range(32):
    for j in range(2,10):
        if i**j<x:
            ans=max(ans,i**j)

print(ans)