N = int(input())
H = [int(h) for h in input().split()]
A = [int(a) for a in input().split()]

#区間の最大値を求めるセグメント木
seg = [0]*(2*N-1)
#for i in range(2*N-2, N-2, -1):
#    seg[i] = A[i-N+1]
    
#for i in range(N-2, -1, -1):
#    seg[i] = max(seg[2*i+1], seg[2*i+2])
    
def update(k, x):
    k += N-1
    seg[k] = x
    while k:
        k = (k-1)//2
        seg[k] = max(seg[2*k+1], seg[2*k+2])
        
def query(p, q):
    p += N-1
    q += N-2
    res = 0
    while q-p > 1:
        if p&1 == 0:
            res = max(res, seg[p])
        if q&1 == 1:
            res = max(res, seg[q])
            q -= 1
        p //= 2
        q = (q-1)//2
    if p == q:
        res = max(res, seg[q])
    else:
        res = max(res, seg[p], seg[q])
    return res

dp = [0]*N
dp[0] = A[0]
update(H[0]-1, A[0])
for i in range(N-1):
    dp[i+1] = query(0, H[i+1])+A[i+1]
    update(H[i+1]-1, dp[i+1])
    
print(max(dp))