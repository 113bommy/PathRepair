n=input()
x=list(map(int,input().split()))
ans=0
for i in x[0::2]:
    if i%2==1:
        ans+=1
print(ans)