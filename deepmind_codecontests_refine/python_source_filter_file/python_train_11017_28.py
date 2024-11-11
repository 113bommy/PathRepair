import sys
n = int(input())
INF = 10**18
a_ls = [int(i) for i in sys.stdin.readline().split()]
max_ind = 0
_max = a_ls[0]
min_ind = 0
_min = a_ls[0]

for i, a in enumerate(a_ls, 1):
    if a > _max:
        _max = a
        max_ind = i
    if a < _min:
        _min = a
        min_ind = i


flg = abs(_max) >= abs(_min)
ls = []
if flg:
    for i in range(1,n+1):
        if i != max_ind:
            ls.append((max_ind, i))
    for i in range(1,n):
        ls.append((i, i+1))
else:
    for i in range(1, n + 1):
        if i != min_ind:
            ls.append((min_ind, i))
    for i in range(n, 1, -1):
        ls.append((i, i - 1))
print(len(ls))
for x, y in ls:
    print(x, y)