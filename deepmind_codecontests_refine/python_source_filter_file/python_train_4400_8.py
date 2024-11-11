n, l = input(), list(map(int, input().split()))
ret = list(l)
for i, n in enumerate(l):
    ret[n - 1] = i + 1
print(ret)
