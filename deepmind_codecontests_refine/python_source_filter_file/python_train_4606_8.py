k=[5,1,4,3,2,0]
a=int(input())
ans=0
for i in range(6):
    if a&(1<<i):
        ans+=1<<k[i]
print(ans)
