def s(a):
    res = 0
    for i in range(len(a)):
        curr = a[i]
        res = max(res, curr)
        for j in range(i + 1, len(a)):
            curr |= a[j]
            res = max(res, curr)
    return res



input()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
print(s(a) + s(b))