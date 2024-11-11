n=int(input())
a=list(map(int, input().split()))
ans=0
h=0
for i in a:
    if i>h:
        ans+=1
        h=i
print(ans)