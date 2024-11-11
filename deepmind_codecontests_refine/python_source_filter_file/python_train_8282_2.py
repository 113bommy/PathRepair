import string

n, m = map(int, input().split(' '))
inp = []
for i in range(n):
    inp.append(input())

mn = [[m] * 3 for i in range(n)]  # First for number, second for alphabet and third for special
for i in range(n):
    for j in range(m):
        index = 2
        if inp[i][j] in string.ascii_lowercase:
            index = 1
        elif inp[i][j] in string.digits:
            index = 0

        mn[i][index] = min(mn[i][index], min(j, m - j))

ans = m * 3
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        for k in range(n):
            if i == k or j == k:
                continue
            ans = min(ans, mn[i][1] + mn[j][1] + mn[k][2])

print(ans)