import sys
sys.setrecursionlimit(5000)

N = int(input())
A = [(int(a), i) for i, a in enumerate(input().split())]
A = sorted(A, reverse=True)

memo = {}

def solve(i, l, r):
    if i==N: return 0

    key = (i,l,r)
    if key in memo: return memo[key]
    
    a, loc = A[i]
    score_l = a*abs(l-loc) + solve(i+1, l+1, r)
    score_r = a*abs(r-loc) + solve(i+1, l, r-1)
    retval = max(score_l, score_r)
    memo[key]=retval
    
    return retval
    
print(solve(0, 0, N-1))