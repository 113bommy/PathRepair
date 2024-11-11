N = int(input())

A = list(map(int, input().split()))
A = sorted(A)

ans = sum(A[N::2])
print(ans)
