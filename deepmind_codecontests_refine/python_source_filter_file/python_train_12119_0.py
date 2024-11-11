n=int(input())
a=list(map(int, input().split()))
c=0;
ans=0
for i in range(n):
    if a[i]==i:
        ans+=1
    elif c==0:
        if i==a[a[i]]:
            c+=2
        else:
            c+=1
print(ans+c)
