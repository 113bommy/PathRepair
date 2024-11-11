N = int(input())
A = [int(input()) for _ in range(N)]

m1, m2 = sorted(A)[N-2:]

ans = [m1 if a!=m1 else m2 for a in A]
for a in ans:
  print(a)
