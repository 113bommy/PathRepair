N,S = map(int,input().split())

A = list(map(int,input().split()))

"""
dpなのはそうだろう
普通に行けば、ナップサックdpでいける
S以下のみしか保持しなくていい

始点を保持してしまうと、Sになった時に…？
始点より左にあるやつの個数の和を記録しておけばいい！

連続してなくていいから
"""

dp = [0] * (S+1)
ans = 0
mod = 998244353

for i in range(N):

    ndp = []
    for ll in dp:
        ndp.append(ll)

    if A[i] <= S:
        ndp[A[i]] += i+1
        ndp[A[i]] %= mod

    for j in range(S):

        if j+A[i] <= S:
            ndp[j+A[i]] += dp[j]
            ndp[j+A[i]] %= mod

    ans += ndp[S]
    ans %= mod

    dp = ndp

    #print (dp)

    
print (ans)
