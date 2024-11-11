(n, L) = map(int, input().split())

lst = []
for x in input().split():
    lst.append(int(x))

lst.extend([10 ** 20] * (31 - n))
for x in range(len(lst) - 1):
    lst[x + 1] = min(lst[x + 1], 2 * lst[x])

s = bin(L)[2:]
s = s[::-1]
price = 0
for x in range(len(s)):
    price += int(s[x]) * lst[x]

for x in range(len(lst)):
    if x >= len(s):
        price = min(price, lst[x])
    else:
        if s[x] == '0':
            p = lst[x]
            for y in range(x + 1, len(s)):
                p += int(s[y]) * lst[y]
            price = min(price, p)

print(price)
