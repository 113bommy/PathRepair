for t in range(int(input())):
    n, k = map(int, input().split())
    A = [int(i) for i in input().split()]
    
    c_count = (n//k)*k # Colored element count
    
    B, d, d1 = A[:], dict(), dict()
    
    for i in B:
        d[i] = d[i]+1 if i in d else 1 
    
    for i in range(n):
        if B[i] in d1:
            d1[B[i]].append(i) 
        else:
            d1[B[i]] = [i]
            
    B.sort(key=lambda x: (d[x], x), reverse = True)

    X, i, j, lst = [B[0]], 0, n, B[0]
    while(j > 0):
        if B[i] != lst:
            X.append(B[i])
            lst = B[i]
        i += 1
        j -= 1

    C = []

    a = [int(i) for i in range(k,0,-1)]

    for i in range(len(X)):
        if d[X[i]] > k:
            C += a
            rem = d[X[i]] - k
            while(rem>0):
                C.append(0)
                rem -= 1
        else:
            cal = n - len(C)
            a1 = cal//k
            for i in range(a1):
                C += a
            rem2 = n - len(C)
            while(rem2 > 0):
                C.append(0)
                rem2 -= 1
            break

    b, k = 0, 0
    for i in X:
        Y = d1[i]
        for j in Y:
            B[j] = C[k]
            k += 1
    
    print(*B)

