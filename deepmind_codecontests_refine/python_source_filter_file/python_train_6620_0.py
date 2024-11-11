import sys

n, k = map(int, input().split())
s = list(input())

if s[-1] == 'D':
    print('NO')
    exit()

size, zero = 2*k-1, k-1
dp = [[0]*size for _ in range(n)]
dp[0][zero] = 1

for i in range(n-1):
    for j in range(size):
        if j and (s[i] == 'W' or s[i] == '?'):
            dp[i+1][j] |= dp[i][j-1]
        if s[i] == 'D' or s[i] == '?':
            dp[i+1][j] |= dp[i][j]
        if j+1 < size and (s[i] == 'L' or s[i] == '?'):
            dp[i+1][j] |= dp[i][j+1]

j = -1
if (s[-1] == 'W' or s[-1] == '?') and dp[-1][-1]:
    j = size-1
    s[-1] = 'W'
elif (s[-1] == 'L' or s[-1] == '?') and dp[-1][0]:
    j = 0
    s[-1] = 'L'

if j == -1:
    print('NO')
    exit()

for i in range(n-2, -1, -1):
    if s[i] == 'W':
        assert dp[i][j-1] == 1
        j -= 1
    elif s[i] == 'L':
        assert dp[i][j+1] == 1
        j += 1
    elif s[i] == '?':
        if dp[i][j]:
            s[i] = 'D'
        elif j > 0 and dp[i][j-1]:
            s[i] = 'W'
            j -= 1
        else:
            s[i] = 'D'
            j += 1

assert j == zero
print(*s, sep='')
