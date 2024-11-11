n = int(input())
rows = []
for i in range(int(n)):
    row = input()
    rows.append(row)

count = -1
for seat in rows:
    count += 1
    if seat[0:2] == 'OO' or seat[3:] == 'OO':
        rows[count] = seat.replace('OO', '++', 2)
        print('YES')
        for row in rows:
            print(row)
        break
    if count == n - 1:
        print('NO')