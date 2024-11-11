

N = 10

A = []
for _ in range(N):
    A += [list(input())]

result = "NO"

# \
#  \
for i in range(N // 2 + 1):
    for j in range(N // 2 + 1):
        cross, dots = 0, 0
        for k in range(N // 2):
            if A[i + k][j + k] == '.':
                dots += 1
            elif A[i + k][j + k] == 'X':
                cross += 1
        if cross == 4 and dots == 1:
            result = "YES"


#  /
# /
for i in range(N // 2 + 1):
    for j in range(N // 2, N):
        cross, dots = 0, 0
        for k in range(N // 2):
            if A[i + k][j - k] == '.':
                dots += 1
            elif A[i + k][j - k] == 'X':
                cross += 1
        if cross == 4 and dots == 1:
            result = "YES"

# --
for i in range(N):
    for j in range(N // 2 + 1):
        cross, dots = 0, 0
        for k in range(N // 2):
            if A[i][j + k] == '.':
                dots += 1
            elif A[i][j + k] == 'X':
                cross += 1
        if cross == 4 and dots == 1:
            result = "YES"

# |
# |
for i in range(N // 2 + 1):
    for j in range(N):
        cross, dots = 0, 0
        for k in range(N // 2):
            if A[i + k][j] == '.':
                dots += 1
            elif A[i + k][j] == 'X':
                cross += 1
        if cross == 4 and dots == 1:
            result = "YES"

print(result)
