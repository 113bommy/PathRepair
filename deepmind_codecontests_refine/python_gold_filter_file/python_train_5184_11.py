n = int(input())
A=[int(i) for i in input().split()]
MOD = 1000000007
ans = 1
cnt = [0]*(n+1)
cnt[0]=3

for i in range(n):
    ans = ans * cnt[A[i]] %MOD
    cnt[A[i]]-=1
    cnt[A[i]+1]+=1
    if ans==0:
        break
print(ans)
