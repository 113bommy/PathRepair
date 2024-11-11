s = input()

n = len(s)
good = False
for i in range(n):
    for j in range(i + 1, n):
        if s[:i] + s[j:] == 'CODEFORCES':
            good = True

print('YES' if good else 'NO')
