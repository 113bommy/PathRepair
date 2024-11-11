number = input()
a, b = list(map(int, input().split()))


def prefix_remainder(s, m):
    rem = []
    curr = 0
    for ch in s:
        curr = (curr * 10 + int(ch)) % m
        rem.append(curr)
    return rem


def suffix_remainder(s, m):
    rem = []
    curr, mul = 0, 1
    for i in range(len(s) - 1, -1, -1):
        ch = s[i]
        curr = (int(ch) * mul + curr) % m
        mul = (mul*10) % m
        rem.append(curr)
    rem.reverse()
    return rem


# print(number, a, b)
prefix = prefix_remainder(number, a)
suffix = suffix_remainder(number, b)

# print(prefix, suffix, number)

for i in range(len(number)):
    if i < len(number) - 1:
        if prefix[i] == 0 and suffix[i + 1] == 0 and number[i + 1] != '0':
            print('YES')
            print(number[:i + 1])
            print(number[i + 1:])
            exit()
print('NO')