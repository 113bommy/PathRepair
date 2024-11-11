x=int(input())
ans=0
for i in range(33):
    for j in range(2,10):
        if i**j<=x:
            ans=max(ans,i**j)

print(ans)