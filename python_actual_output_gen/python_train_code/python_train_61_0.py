def inp():
    return map(int, input().split())


def arr_inp():
    return [int(x) for x in input().split()]


n, k = inp()
id, ans, tem = arr_inp(), 1, 1
for i in range(2, k + 1):
    if ans >= k:
        break
    tem = ans
    ans += i
print(id[k - tem - 1])
