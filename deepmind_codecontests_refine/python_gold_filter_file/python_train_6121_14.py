n=int(input())
a=list(map(int,input().split()))
ans=[0]*n
for i in range(len(a)):
    ans[a[i]-1]=i+1
print(*ans)