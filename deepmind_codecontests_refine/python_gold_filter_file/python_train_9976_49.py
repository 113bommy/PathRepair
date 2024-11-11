x=int(input())
ans=0
for i in range(1,33):
    for j in range(2,11):
        if i**j<=x:
            ans=max(ans, i**j)
print(ans)