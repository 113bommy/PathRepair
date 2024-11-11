n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
val = a[0]
j = 0
for i in range(m):
    while b[i] > val:
        j += 1
        val += a[j]

    print(j + 1, b[i] - val - a[j] + 1)
