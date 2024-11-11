n = int(input())
arr = []
for i in range(n):
    arr.append(list(input()))
count = 0
if n <= 2:
    print(0)

else:
    for i in range(n - 1):
        for j in range(1, n - 1):
            if arr[i][j] == arr[i - 1][j - 1] == arr[i - 1][j + 1] == arr[i + 1][j - 1] == arr[i + 1][j + 1] == 'X':
                count += 1
    print(count)

