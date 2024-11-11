m = [input() for i in range(3)]
print('YES' if all(m[i][j] == m[2 - i][2 - j] for i in range(2) for j in range(2)) else 'NO')