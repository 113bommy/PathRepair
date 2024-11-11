for _ in range(int(input())):
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    if k == 1:k = 1
    elif k%2:k = 3
    else:k = 2
    for __ in range(3):
        m = max(A)
        for i in range(n):
            A[i]  = (m-A[i])
    print(*A)