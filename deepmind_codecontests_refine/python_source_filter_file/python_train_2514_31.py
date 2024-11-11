nDigits = int(input())
a = list(map(int, list(input())))
f = list(map(int, input().split()))

for i in range(nDigits):
    if f[a[i] - 1] > a[i]:
        j = i
        while j < nDigits and f[a[j] - 1] > a[j]:
            a[j] = f[a[j] - 1]
            j += 1
        break
print(''.join(map(str, a)))