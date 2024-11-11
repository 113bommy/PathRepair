N, K = map(int, input().split())
A = sorted([int(a) for a in input().split()])
F = sorted([int(a) for a in input().split()])[::-1]
l = -1
r = sum(A)
while r-l > 1:
    m = (l+r)//2
    if sum([max(0, A[i] - m//F[i]) for i in range(N)]) <= K:
        r = m
    else:
        l = m
print(r)