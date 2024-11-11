def binary_pow(k, x):
    if (x == 1):
        return k
    if (x == 0):
        return 1
    else:
        if (x % 2 == 0):
            return binary_pow(k, x // 2) * binary_pow(k, x // 2)
        else:
            return k * (binary_pow(k, (x - 1) // 2)) * binary_pow(k, (x - 1) // 2)


def func(x):
    global k
    left = 0
    right = 50
    while (right - left > 1):
        mid = (left + right) // 2
        if binary_pow(k, mid) < x:
            left = mid
        else:
            right = mid
    ans = []
    for i in range(right, -1, - 1):
        v = x // binary_pow(k, i)
        ans.append(v)
        x -= (v * binary_pow(k, i))
    return ans[::-1]


t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    good = [0] * 100
    for i in range(n):
        x = func(a[i])
        for j in range(len(x)):
            good[j] += x[j]
    f = True
    for i in good:
        if i > 1:
            f = False
            break
    if f:
        print("YES")
    else:
        print("NO")
