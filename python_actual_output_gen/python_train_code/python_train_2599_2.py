n = int(input())
matrix = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    matrix[i] = list(map(int, input().split()))

s = 0
for i in range(n):
    s += matrix[i][i]
    s += matrix[n-i-1][n-i-1]
    s += matrix[n//2][i]
    s += matrix[i][n//2]

s -= 3*matrix[n//2][n//2]
print(s)
