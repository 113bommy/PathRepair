a, b = map(int, input().split())

buf = [['.'] * 100 for _ in range(50)] + [['#'] * 100 for _ in range(50)]

bd, bm = divmod(b - 1, 50)
for i in range(0, (bd + (bm > 0)) * 2, 2):
    for j in range(0, bm * 2 if i == bd * 2 else 100, 2):
        buf[i][j] = '#'

ad, am = divmod(a - 1, 50)
for i in range(0, (ad + (am > 0)) * 2, 2):
    for j in range(0, am * 2 if i == ad * 2 else 100, 2):
        buf[i + 51][j] = '.'

print(100, 100)
print('\n'.join(''.join(row) for row in buf))
