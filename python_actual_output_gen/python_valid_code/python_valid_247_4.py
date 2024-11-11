a,b=map(int,input().split())
l=list(map(int,input().split()))
max=0
ans=0
for i in range(a):
    if (l[i])//b>=max:
        max=(l[i])//b

        ans=i

print(ans+1)

