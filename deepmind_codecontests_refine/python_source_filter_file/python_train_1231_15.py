N, H = map(int, input().split())
A = []
B = []
for _ in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

A.sort(reverse=True)
B.sort(reverse=True)

c = 0
for b in B:
    if b < A[0] or H < 0:
        break
    H -= b
    c += 1

if H > 0:
    c += H // A[0]
    if H % A[0] != 0:
        c += 1

print(c)