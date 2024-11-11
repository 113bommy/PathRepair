n = int(input())
A = list(map(int, input().split()))
s = 0
l = A[0]
i = 0
while i <= n - 1:
    l = max(l, A[i])
    if i + 1 == l:
        s += 1
    i += 1