n = int(input())
rows = []
for _ in range(n):
    rows.append(input())

ret = 'NO'

for i in range(len(rows)):
    row = rows[i]
    if row[:2] == 'OO' or row[-2:] == 'OO':
        if row[:2] == 'OO':
            row = '++' + row[2:]
        if row[-2:] == 'OO':
            row = row[:-2] + '++'
        ret = 'YES'
        rows[i] = row
        break

print(ret)
if ret == 'YES':
    for row in rows:
        print(row)
