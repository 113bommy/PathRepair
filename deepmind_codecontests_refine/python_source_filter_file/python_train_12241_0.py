n = input()
s = input()
# n = len(s)

depth = 0
maxdepth = 0
delta = 0

for i in s:
    if i == '[':
        depth += 1
    else:
        depth -= 1
    maxdepth = max(depth, maxdepth)

for i in range(len(s) - 1):
    if s[i] == '[' and s[i + 1] == ']':
        delta += 1

h = (2 * maxdepth + 1)
l = (2 * len(s) + delta)

# res = [[' '] * l] * h
res = [[' ' for i in range(l)] for j in range(h)]

def printbkt(index, depth, c):
    if c == '[':
        res[depth][index] = '+'
        res[depth][index + 1] = '-'
        res[h - 1 - depth][index] = '+'
        res[h - 1 - depth][index + 1] = '-'
        for i in range(depth + 1, h - depth - 1):
            res[i][index] = '|'
    else:
        res[depth][index] = '-'
        res[depth][index + 1] = '+'
        res[h - 1 - depth][index] = '-'
        res[h - 1 - depth][index + 1] = '+'
        for i in range(depth + 1, h - depth - 1):
            res[i][index + 1] = '|'

# for i in res:
#     print(''.join(i))

printbkt(0, 0, '[')
# printbkt(1, 1, '[')
# printbkt(4, 1, ']')


# for i in res:
#     print(''.join(i))

s = s + '$'

index = 0

depth = 1

for i in range(1, int(n)):
    if s[i] == '[':
        depth += 1
    else:
        depth -= 1
    # print(depth)
    if s[i - 1] == '[' and s[i] == ']':
        index += 3
        printbkt(index, depth, ']')
    elif s[i] == '[':
        if s[i] != s[i - 1]:
            index += 1
        index += 1
        printbkt(index, depth - 1, '[')
    else:
        if s[i] != s[i - 1]:
            index += 1
        index += 1
        printbkt(index, depth, ']')


for i in res:
    print(''.join(i))
    # print()
