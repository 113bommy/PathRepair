n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
aa = [0]
for i in range(len(a)):
    aa.append(aa[i] + a[i])
for i in range(len(b)):
    left = 0
    right = len(aa) - 1
    while right - left > 1:
        mid = (left + right) // 2
        if b[i] <= aa[mid]:
            right = mid
        else:
            left = mid
    print(right, b[i] - aa[right - 1])
