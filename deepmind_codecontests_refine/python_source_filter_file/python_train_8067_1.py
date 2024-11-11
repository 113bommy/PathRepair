mul=lambda A,B,r:[[max([A[i][k]+B[k][j] for k in r if A[i][k] and B[k][j]],default=0) for j in r] for i in r]

def binpower(A,n,e):
    r  = range(n)
    B  = A  #A^0 is invalid, thus start from A^1
    e -= 1
    while True:
        if e &1: B = mul(B,A,r)
        e =e>>1
        if e==0: return B
        A =mul(A,A,r)

def f(l,n,T):
    # Part 1: cal M
    h = max(l)+1
    N = [[0]*h for _ in range(h)]
    Q = [[0]*h for _ in range(h)] 
    M = [[0]*n for _ in range(n)]
    for j in range(n):
        # update Mij based on Quv,(j-1)
        for i in range(n):
            M[i][j]=Q[l[i]][l[j]]+1 if l[i]<=l[j] else 0
        # update Nuv,(j) and Quv,(j)
        v = l[j]
        for u in range(1,v+1):
            N[u][v] += 1
            for vv in range(v,h):
                Q[u][vv] = max(Q[u][vv],N[u][v])
    return max(max(binpower(M,n,T)))

n,T = list(map(int,input().split()))
l   = list(map(int,input().split()))
print(f(l,n,T))

