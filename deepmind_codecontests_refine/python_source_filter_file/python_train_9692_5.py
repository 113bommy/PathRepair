n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(input())
begin_raw = end_raw = int
for i in range(n):
    if 'B' in arr[i]:
        begin_raw = i
        break
for i in range(n):
    if 'B' in arr[::-1][i]:
        end_raw = i
        break
begin_col = end_col = int
for j in range(m):
    for i in range(n):
        if arr[i][j] == 'B':
            begin_col = j
            break
for j in range(m - 1, -1, -1):
    for i in range(n):
        if arr[i][j] == 'B':
            end_col = j
            break
print((begin_raw + end_raw) // 2 + 1,
      (begin_col + end_col) // 2 + 1)
