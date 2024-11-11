n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
b = list(map(int, input().split()))
a.pop()
for i in range(1, n):
    a[i] += a[i - 1]
ind = 0
for i in range(m):
    if b[i] > a[-1]:
        print(n, b[i] - a[-1])
    else:
        for j in range(ind, n):
            if b[i] <= a[j]:
                print(j, b[i] - a[j - 1])
                ind = i
                break