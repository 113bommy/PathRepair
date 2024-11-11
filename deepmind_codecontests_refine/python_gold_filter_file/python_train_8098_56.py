n=int(input())
ans=0
for i in range(1,1+n):
    if len(str(i))%2==1:ans+=1
print(ans)