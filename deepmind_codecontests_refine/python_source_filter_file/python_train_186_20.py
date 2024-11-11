N, K, Q = map(int, input().split())
A = [int(i) for i in input().split()]

def solve() :
    if Q == 1 : return min(A)
        
    ret = float('inf')
    for i in range(N) :
        l = -1
        for j in range(i, max(-1, i - K), -1) :
            if A[j] < A[i] :
                l = j
                break
        r = N      
        for j in range(i, min(N, i + K)) :
            if A[j] < A[i] :
                r = j
                break
                
        if r - l - 1 < K :
            continue
            
        B = A[::]
        B.pop(i)
        
        C = [-1]
        for j in range(N - 1) :
            if B[j] < A[i] :
                C.append(j)
        C.append(N - 1)
        
        D = []
        for j in range(len(C) - 1) :
            if C[j+1] - C[j] >= K :
                D += sorted(B[C[j]+1:C[j+1]])[:C[j+1] - C[j] - K]
        
        if len(D) >= Q - 1 :
            D.sort()
            ret = min(ret, D[Q-2] - A[i])

    return ret
    
print(solve())