t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(a) for a in input().split()]
    if len(set(A)) == 1:
        print(-1)
    else:
        m = max(A)
        for i, a in enumerate(A):
            if a == m and \
            ((i > 0 and A[i - 1] != m) or (i < len(A) and A[i + 1] != m)):
                print(i + 1)
                break
