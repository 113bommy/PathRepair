n=int(input())
a=list(map(int,input().split()))
ans=[0]*n
for i in range(n):
    j=a[i]
    ans[j-1]=i+1
print(ans)