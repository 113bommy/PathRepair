n,d = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()
ans=0
for i in range(n-1):
    if a[i+1]-a[i] > 2*d:
        ans+=2
    elif a[i+1]-a[i] == 2*d:
        ans+=1
print(ans)
    