def put(): return [int(x) for x in input().split()]

n,m = put()
a = list(put())
#a = lambda(x: x%(m+1))
dp = [0]*(m)
dp[0] = 1
ans = 'NO'
for i in range(n):
    tmp = [0]*(m)
    for j in range(m):
        tmp[j] += dp[j]
        mod = (j+a[i])%(m)
        tmp[mod] += dp[j]
    if dp[0]>1:
        ans = 'YES'
        break
    #print(tmp)
    dp = tmp

print(ans)