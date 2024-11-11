n,m = tuple(int(i) for i in input().split())
A = [[int(j) for j in input().split()] for k in range(n)]
b = [int(input()) for p in range(m)]
print(b)
R = [sum([A[p][q] * b[q] for q in range(m)]) for p in range(n)]

for r in R:
    print(str(r))
