n = int(input())
arr = list(map(int, input().split()))
m = min(arr)
first = arr.index(m) + 1
tmp = 1
output = -1
for i in range(first, len(arr)):
    if arr[i] == m:
        if output < 0:
            output = tmp
        else:
            output = min(output, tmp)
        tmp = 1
    else:
        tmp += 1
    if output == 1:
        break

print(output)