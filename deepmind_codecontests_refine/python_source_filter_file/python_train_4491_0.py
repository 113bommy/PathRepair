mima = 10 ** 9
mami = -10 ** 9
asan = []
for _ in range(int(input())):
    c, x, y = input().split()
    x, y = int(x), int(y)
    x, y = min(x, y), max(x, y)
    if c == '+':
        mima = min(mima, y)
        mami = max(mami, x)
    else:
        if x >= mami and y >= mima:
            asan.append('yes')
        else:
            asan.append('no')
print('\n'.join(asan))