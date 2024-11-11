ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

def main():
    n,m = mi()
    tree = [set() for _ in range(n)]
    for i in range(m):
        s,t = mi()
        tree[s-1].add(t-1)
    dp = [0]*n
    dpl = [0]*n
    for i in range(n-1):
        dpl[i] = len(tree[i])
    for i in reversed(range(n-1)):
        for k in tree[i]:
            dp[i] += dp[k] 
        dp[i] /= dpl[i]
        dp[i] += 1
    ans = dp[0]
    
    def func(ss,tt):
        tmp = 0
        for l in tree[ss]:
            if l == tt:
                continue
            tmp += dp[l]
        tmp = tmp/(dpl[ss] -1) + 1
        if tmp > dp[ss]:
            return dp[0]
        else:
            dp[ss] = tmp
        
        for a in reversed(range(ss)):
            tmp = 0
            for b in tree[a]:
                tmp += dp[b]
            dp[a] = tmp/dpl[a] + 1
        
        return dp[0]
    
    for i in range(n-1):
        if len(tree[i]) == 1:
            continue
        for k in tree[i]:
            ans = min(ans,func(i,k))
    print(ans)

main()