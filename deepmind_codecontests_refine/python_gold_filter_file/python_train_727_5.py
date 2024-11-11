def swap(A,i,j):
    A[i],A[j] = A[j],A[i]
    return A

def mincost(A):
    B = sorted(A)
    cost = 0
    
    for i, bi in enumerate(B):
        t = 0
        j = A.index(bi)
        tmp_cost = 0
        
        # swap in a cyclic group
        while j != i:
            t += 1
            bj = B[j]
            k = A.index(bj)
            tmp_cost += bi + bj
            swap(A,j,k)
            j = k
        
        # diff. to swap with min(B)
        dec = t * (bi - B[0])
        inc = 2 * (bi + B[0])
        
        if dec < inc:
            cost += tmp_cost
        else:
            cost += tmp_cost - dec + inc
    return cost

if __name__ == "__main__":
    input()
    A = list(map(int, input().strip().split()))
    cost = mincost(A)
    print(cost)