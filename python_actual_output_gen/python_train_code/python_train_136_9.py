N = int(input())
A = [int(input()) for _ in range(N)]
m1,m2 = sorted(A)[-2:]

for i in A:
    print(m2 if i==m1 else m1)