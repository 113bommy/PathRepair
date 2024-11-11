import sys, math
input = sys.stdin.readline

for _ in range(int(input())):
    n, m, a, b = map(int, input().split())
    A = sorted(map(int, input().split()))
    if a < b:
        t = b - 1
    else:
        t = n - b
    ans = 0
    k = min(abs(b - a - 1), m)
    j = m - 1
    for i in range(1, k + 1):
        while j >= 0 and i + A[j] > t:
            j -= 1
        if j >= 0:
            ans += 1
            j -= 1
        if j < 0: break
    print(ans)
