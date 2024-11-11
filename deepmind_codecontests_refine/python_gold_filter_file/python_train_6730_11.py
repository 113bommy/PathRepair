n = int(input())
X = list(map(int, input().split()))
S = set(X)

if len(S) == 1:
    print(n)
    print(*X)

if len(S) == 2:
    m = min(X)
    M = max(X)
    if M-m == 1:
        print(n)
        print(*X)
    else:
        C = [0, 0, 0]
        for x in X:
            if x == m:
                C[0] += 1
            else:
                C[2] += 1
        res = 10**18
        mi = -1
        for i in range(-n, n+1):
            if C[0]+i < 0 or C[1]-2*i < 0 or C[2]+i < 0:
                continue
            if C[0]+i > n or C[1]-2*i > n or C[2]+i > n:
                continue
            temp = min(C[0], C[0]+i)+ min(C[1], C[1]-2*i)+min(C[2], C[2]+i)
            if temp <= res:
                res = temp
                mi = i
        print(res)
        ans = [m]*(C[0]+mi)+[m+1]*(C[1]-2*mi)+[M]*(C[2]+mi)
        print(*ans)

if len(S) == 3:
    m = min(X)
    M = max(X)
    if M-m == 1:
        print(n)
        print(*X)
    else:
        C = [0, 0, 0]
        for x in X:
            if x == m:
                C[0] += 1
            elif x == M:
                C[2] += 1
            else:
                C[1] += 1
        res = 10**18
        mi = -1
        for i in range(-n, n+1):
            if C[0]+i < 0 or C[1]-2*i < 0 or C[2]+i < 0:
                continue
            if C[0]+i > n or C[1]-2*i > n or C[2]+i > n:
                continue
            temp = min(C[0], C[0]+i)+ min(C[1], C[1]-2*i)+min(C[2], C[2]+i)
            if temp <= res:
                res = temp
                mi = i
        print(res)
        ans = [m]*(C[0]+mi)+[m+1]*(C[1]-2*mi)+[M]*(C[2]+mi)
        print(*ans)
