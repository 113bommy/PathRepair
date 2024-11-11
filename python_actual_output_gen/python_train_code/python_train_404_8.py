n=int(input())
ans=list(map(int,input().split()))
for i in range(len(ans)-2,-1,-1):
    ans[i]+=ans[i-1]-1
print(sum(ans))