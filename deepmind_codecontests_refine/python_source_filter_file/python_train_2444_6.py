n, m = map(int, input().split(' '))
s = [list(input()+'.') for i in range(n)] 
s += [list('.'*(m + 1))]

def solve():
    flag = False
    for i in range(n):
        for j in range(m):
            if s[i][j] != '.':
                d = 0
                d += (s[i + 1][j] == s[i][j])
                d += (s[i - 1][j] == s[i][j])
                d += (s[i][j + 1] == s[i][j])
                d += (s[i][j - 1] == s[i][j])
                if d < 2:
                    s[i][j] = '.'
                    flag = True
    return flag

for _ in range(50):
    solve()

for i in range(n):
    for j in range(m):
        if s[i][j] != '.':
            print ('Yes')
            exit()

print('No')
