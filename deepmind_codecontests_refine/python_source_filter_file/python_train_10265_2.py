def gen(pr, n):
    global seq
    if len(pr) >= n:
        seq.append(pr)
    else:
        gen(pr + '0', n)
        gen(pr + '1', n)


n, m = map(int, input().split())
matrix = []
pref = [[] for i in range(n)]
seq = []
for i in range(n):
    matrix.append(input()[1:m + 1])
    j = m - 1
    while j >= 0 and matrix[i][j] == '0':
        j -= 1
    tmp1 = (j + 1) * 2
    j = 0
    while j < m and matrix[i][j] == '0':
        j += 1
    tmp2 = (m - j) * 2
    pref[n - i - 1] = [tmp1, tmp2]
i = n - 1
while i >= 0 and pref[i] == [0, 0]:
    i -= 1
gen('0', i + 1)
n = i + 1
mi = float('inf')
for i in seq:
    res = 0
    for j in range(n - 1):
        if i[j] == i[j + 1]:
            res += pref[j][int(i[j])] + 1
        else:
            res += m + 2
    res += pref[-1][int(i[-1])] // 2
    if res < mi:
        mi = res
print(mi)