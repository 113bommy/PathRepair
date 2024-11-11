n=int(input())
ar=list(map(int,input().split()))
ans=0
for i in range(n):
    ans+=((i%2)&(ar[i]%2))
print(ans)
