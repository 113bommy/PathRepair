N = int(input())
S = [list(input()) for i in range(N)]

def is_ok(mat):
    n = len(mat)
    for i in range(n):
        for j in range(n):
            if mat[i][j] != mat[j][i]:
                return False
    return True

count = 0
A = 1
for B in range(N):
    next_S = [S[(i+B) % N] for i in range(N)]
    if is_ok(next_S):
        count += 1

print(count * N)