
n = int(input())
a = list(map(int, input().split()))

good = True

b = n - a[0]

for i in range(n):
    if i % 2 == 0:
        if (n + i - a[i]) % n != b:
            good = False
    else:
        if (a[i] - i + n) % n != b:
            good = False

if good:
    print("Yes")
else:
    print("No")


