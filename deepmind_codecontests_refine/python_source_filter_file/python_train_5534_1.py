def check(a):
    for x, y in zip(a[:-1], a[1:]):
        if x >= y or y > 2*x:  
            return False
    return True

def solve(n, k):
    if n < k*(k+1) // 2:
        return 'NO', None
    
    ans    = list(range(1, k+1))
    plus   = n - sum(ans)
    add    = plus // k
    r      = plus % k
    
    for i in range(k):
        ans[i] += add
        
    if r != 0: 
        last     = 2*ans[-2] - ans[-1] 
        ans[-1] += min(last, r)
        if r > last:
            ans[-2] += r-last 
            
    if check(ans) == True:
        return True, ans
    
    return 'NO', None
    
n, k = map(int, input().split())
flg,ans=solve(n, k)
if flg=='NO':
    print(flg)
else:
    print(flg)
    print(' '.join([str(x) for x in ans]))