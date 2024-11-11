r, c = map(int, input().split())
L = [str(input()) for _ in range(r)]
C = [0 for _ in range(c)]
R = [0 for _ in range(r)]
for i in range(r):
    for j in range(c):
        if L[i][j] == "S":
            R[i] = 1
            C[j] = 1


print(r*c-sum(C)*sum(R))
