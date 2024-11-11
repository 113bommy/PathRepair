n = int(input())
a = [int(i) for i in input().split()]
ma = 0
c = 0
for i in range(1, n):
    if a[i] > a[i-1]: c += 1
    else:
        ma = max(c, ma)
        c = 1
ma = max(ma, c)
print(ma)