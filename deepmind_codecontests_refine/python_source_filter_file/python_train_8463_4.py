def inp():
    return map(int, input().split())


def arr_inp(n):
    return [input() for x in range(n)]


def get_col(arr, i):
    return [row[i] for row in arr]

def print_arr(arr):
    print(*arr, sep='')

n, m = inp()
a = arr_inp(n)
row_beg, row_end, col_beg, col_end = 0, 0, 0, 0

for i in range(n):
    if (a[i].count('*') > 0):
        row_beg = i
        break

for i in range(n - 1, row_beg, -1):
    if (a[i].count('*') > 0):
        row_end = i
        break

for i in range(m):
    col = get_col(a, i)
    if (col.count('*') > 0):
        col_beg=i
        break
for i in range(m-1,col_beg,-1):
    col=get_col(a,i)
    if (col.count('*') > 0):
        col_end = i
        break

for i in range(row_beg,row_end+1):
    print_arr(a[i][col_beg:col_end+1])
