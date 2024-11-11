import sys
input = sys.stdin.readline

Q = int(input())
for _ in range(Q):
    N = int(input())
    K = N//2
    A = list(map(int, input().split()))
    ans = []
    if A.count(0) >= K:
        ans = [0] * K
    else:
        if K%2 == 0:
            ans = [1] * K
        else:
            ans = [1] * (K+2)
    print(len(ans))
    print(*ans)