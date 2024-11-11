n = int(input())
a = [int(i) for i in input().split()]

a.sort()

res_amount = 0
res = a[-1] - a[1]

for i in range(1, len(a)):
    if a[i] - a[i - 1] < res:
        res_amount = 1
        res = a[i] - a[i - 1]
        continue
    if a[i] - a[i - 1] == res:
        res_amount += 1

print("{0} {1}".format(res, res_amount))
