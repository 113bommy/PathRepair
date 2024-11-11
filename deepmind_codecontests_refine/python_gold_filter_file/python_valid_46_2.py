def overlap(min1, max1, min2, max2):
    if max1 < min2 or max2 < min1:
        return 0
    return max(0, min(max1, max2) - max(min1, min2)) + 1


n = int(input())
arr = list(map(int, input().split()))
ans = 0
li = []
for i in range(0, n, 2):
    temp = 0
    a = 0
    b = arr[i] - 1
    temp += arr[i]
    flag = 0
    ans = 0
    for j in range(i + 1, n):
        c, d = 0, 0
        if j % 2 == 0:
            temp += arr[j]
        else:
            c = temp - 1
            d = temp - arr[j]
            temp -= arr[j]
            ans += overlap(a, b, d, c)
            b = min(b, temp)
        if temp < 0:
            break
    li.append(ans)
print(sum(li))
