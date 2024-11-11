import sys
n, m = map(int, input().split())
o_map = ['.'*(m+2)]
o_map.extend(['.' + sys.stdin.readline() + '.' for i in range(n)])
o_map.append(['.'*(m+2)])

# forward method num
f_method = [[0]*(m+2) for i in range(n+2)]
# reverse method num
r_method = [[0]*(m+2) for i in range(n+2)]

MOD = 10**9 + 93
# forward calc
f_method[1][1] = 1
for i in range(1, n+1):
    for j in range(1, m+1):
        if o_map[i][j] == '.' and i + j != 2:
            f_method[i][j] = (f_method[i-1][j] + f_method[i][j-1]) % MOD

r_method[n][m] = 1
for i in range(n, 0, -1):
    for j in range(m, 0, -1):
        if o_map[i][j] == '.' and i + j != m + n:
            r_method[i][j] = (r_method[i+1][j] + r_method[i][j+1]) % MOD
if f_method[n][m] == 0:
    #if n == 175 and m == 119:
    #    print(f_method[n-1][m], f_method[n][m-1])
    print(0)
else:
    for i in range(1, n+1):
        for j in range(1, m+1):
            if i + j in [2, m+n]:
                continue

            if (f_method[i][j] * r_method[i][j]) % MOD == f_method[n][m]:
                print(1)
                exit()
    print(2)
