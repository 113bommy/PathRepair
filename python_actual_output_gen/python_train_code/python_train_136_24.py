N = int(input())
A = [int(input()) for _ in range(N)]

m1, m2 = sorted(A, reversed=True)[0:2]
for a in A:
    print(m2 if a == m1 else m1)