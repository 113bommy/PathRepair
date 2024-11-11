t = int(input())
for i in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    curr = A[0]
    for j in range(1, n):
        curr = min(curr, A[j] - (A[j - 1] - curr))
        if curr < 0:
            print("NO")
            break
    else:
        print("YES")
