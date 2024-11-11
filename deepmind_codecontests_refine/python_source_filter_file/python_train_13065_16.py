n, m = map(int, input().split())
arr = []
tf = m * n
for i in range(n):
    arr.append(list(map(int, input().split())))
for i in range(n):
    j = 0
    while j < m:
        if arr[i][j] == arr[i][j + 1] == 0:
            tf -= 1
        j += 2
print(tf)