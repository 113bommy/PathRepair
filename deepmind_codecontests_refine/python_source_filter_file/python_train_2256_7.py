n = int(input())
a = list(map(int, input().split()))
n *= 2
k = 0
for i in range(n - 1):
    for j in range(i + 1, n):
        if a[j] == a[i]:
            k += j - i - 1
            for l in range(i + 2, j + 1):
                a[l] = a[l - 1]
            a[i + 1] = a[i]
print(k)
