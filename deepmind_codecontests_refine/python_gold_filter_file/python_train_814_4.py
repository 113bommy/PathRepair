a, b, c = input().split()
print('YES' if a[-1:] == b[0:1] and b[-1:] == c[0:1] else 'NO')