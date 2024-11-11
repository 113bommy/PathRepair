n = int(input())
a = list(map(int,input().split()))
ans=10**13
for i in [1,-1]:
    b=0
    c=0
    for j in a:
        b+=j
        if b*i<=0:
            c+=abs(b-i)
            b=i
        i*=-1
    ans=min(ans,c)
print(ans)