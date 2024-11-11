n = int(input())
a = list(map(int, input().split()))
b = input()

l, r = -10 ** 9, 10 ** 9

for i, el in enumerate(b[4:], 4):
    if b[i - 4: i] == '0000' and el == '1':
        l = max(l, max(a[i - 4: i + 1]) + 1)

    elif b[i - 4: i] == '1111' and el == '0':
        r = min(r, min(a[i - 4: i + 1]) - 1)

print(l, r)
