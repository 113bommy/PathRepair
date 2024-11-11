from collections import Counter


def only_one(a):
    return len(Counter(a)) == 1


colors = list(map(int, input().split()))

pairs = ((1, 3), (2, 6), (4, 5))
new_pairs = list()

f = False
c = 0
count = 0
pair = tuple()
for i in pairs:
    a, b = ((i[0] - 1) * 4, i[0] * 4), (((i[1] - 1) * 4, i[1] * 4))
    if only_one(colors[a[0]: a[1]]) and only_one(colors[b[0]: b[1]]):
        f = True
        c += 1
        pair = i
    if only_one(colors[a[0]: a[1]]):
        count += 1
    if only_one(colors[b[0]: b[1]]):
        count += 1
    else:
        new_pairs.append(i)

if not f or c != 1 or count != 2:
    print('NO')

else:
    C = colors
    if pair == pairs[0]:
        one = [C[12], C[13], C[4], C[5], C[16], C[17], C[20], C[21]]
        two = [C[14], C[15], C[6], C[8], C[18], C[19], C[22], C[23]]

        if one[2:] + one[:2] == two or one[6:] + one[:6] == two:
            print('YES')
            exit()

    elif pair == pairs[1]:
        one = [C[2], C[3], C[16], C[18], C[9], C[8], C[15], C[13]]
        two = [C[0], C[1], C[17], C[19], C[11], C[10], C[14], C[12]]

        if one[2:] + one[:2] == two or one[6:] + one[:6] == two:
            print('YES')
            exit()

    elif pair == pairs[2]:
        one = [C[0], C[2], C[4], C[6], C[8], C[10], C[23], C[21]]
        two = [C[1], C[3], C[5], C[7], C[9], C[11], C[22], C[20]]

        if one[2:] + one[:2] == two or one[6:] + one[:6] == two:
            print('YES')
            exit()

    print('NO')
