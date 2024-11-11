x=int(input())
ans=1
for i in range(1,x-1):
    if len(str(i))%2!=0:
        ans+=1
print(ans)