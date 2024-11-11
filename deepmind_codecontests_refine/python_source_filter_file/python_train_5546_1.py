


for _ in range(int(input())):
    
    N = int(input())
    
    A = [[i, 1] if i > 0 else [-i, -1] for i in map(int, input().split())]
    
    A.sort()
    
    ans = 1
    for i in range(5):
        ans *= A[i][0] * A[i][1]
    
    x = 1
    for i in range(-5, 0):
        x *= A[i][0] * A[i][1]
    if x >= 0:
        print(x)
        continue
    y = x
    for i in range(-5, 0):
        if A[i][1] == -1:
            y //= -A[i][0]
            break
    z = x
    b = False
    for i in range(-5, 0):
        if A[i][0] == 1:
            z //= A[i][0]
            b = True
            break
    i = N - 6
    while i >= 0:
        if A[i][1] == 1:
            ans = max(ans, y * A[i][0])
            break
        i -= 1
    if b:
        i = N - 6
        while i >= 0:
            if A[i][1] == -1:
                ans = max(ans, -z * A[i][0])
                break
            i -= 1
    print(ans)