n=int(input())
v=sorted(list(map(int,input().split())))
ans=v[0]
for i in range(1,n):
    ans=(ans+v[i])//2
print(ans)