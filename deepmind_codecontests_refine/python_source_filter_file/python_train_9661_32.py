import bisect
n = int(input())
a = list(map(int, input().split()))

a.sort()
ope = []
max_num = a[-1]
min_num = a[0]
p = bisect.bisect_left(a, 0)
for i in range(1, max(p, 1)):
    ope.append([max_num, a[i]])
    max_num -= a[i]
for i in range(max(p, 1), n - 1):
    ope.append([min_num, a[i]])
    min_num -= a[i]
ope.append([max_num, min_num])
print(max_num - min_num)
for i in range(n - 1):
    print(" ".join(map(str, ope[i])))