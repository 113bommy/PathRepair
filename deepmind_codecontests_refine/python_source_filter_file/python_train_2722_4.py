n = int(input())
l = ['a'] * n
for i in range(n):
    l[i] = list(input())

def check():
    for i in range(n - 2):
        if l[i].count('.') == 0: continue
        if l[i].index('.') == 0 or l[i].index('.') == n - 1:
            return 0
        elif l[i].count('.'):
            a = l[i].index('.')
            if l[i + 1][a - 1] == '.' and l[i + 1][a] == "." and l[i + 1][a + 1] == '.' and l[i + 2][a] == '.':
                l[i][a] = '#'
                l[i + 2][a] = "#"
                l[i + 1][a] = '#'
                l[i + 1][a - 1] = '#'
                l[i + 1][a + 1] = '#'
                return 1
            else:
                return 0
    return 1
for i in range(51):
    b = check()
    if not(b):
        print('NO')
        exit()
if l[n - 1].count('.') or l[n-2].count('.'):
    print('NO')
    exit()
print('YES')