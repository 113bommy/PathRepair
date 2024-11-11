T = int(input())
for case in range(1, T+1):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    for i in range(N):
        A[i] = (A[i],i)
    A.sort()
    last = A[0][1]
    g = 1
    for n, pos in A[1:]:
        if pos < last:
            g += 1
        last = pos
    if g > K:
        print("No")
    else:
        print("Yes")
