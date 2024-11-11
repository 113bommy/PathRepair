M =lambda : map(int,input().split())
n = int(input())
l = list(M())
ans,cnt = 1,1
for i in range(n-1):
    if l[i+1]>=l[i]:
        cnt+=1
        ans = max(cnt,ans)
    else:
        cnt = 1
print(ans)

