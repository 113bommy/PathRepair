n = int(input())
arr = list(map(int, input().split()))
ans = arr.count(0)
for i in range(1, n + 1):
    one = 0
    ind = -1
    j = n - 1
    for j in range(n -1, -1, -1):
        if one == i:
            ind = j
            break
        if arr[j] == 1:
            one += 1
    else:
        if one == i:
            ind = j
        else:
            break
    ans = max(ans, i + arr[:ind].count(0))
print(ans)
