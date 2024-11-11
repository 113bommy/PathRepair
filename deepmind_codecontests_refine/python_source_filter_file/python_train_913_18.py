n=int(input())
v=sorted(list(map(int,input().split())))
ans=v[0]
for i in range(n-1):
    ans=(ans+v[i+1])//2
print(ans)