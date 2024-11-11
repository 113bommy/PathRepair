N = int(input())
A = [int(input()) for _ in range(N)]
if any(a - b > 1for a, b in zip(A, [-1]+A)): print(-1)
else:
    ans = 0
    for a, nxt in zip(A, A[1:]+[0]):
        if a >= nxt:
            ans += a
print(ans)