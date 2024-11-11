a = ['$' * 12]
for i in range(10):
    a.append(list('$' + input() + '$'))
a.append('$' * 12)
flag = False
def count(r, c, dr, dc):
    k = 0
    while a[r][c] == 'X':
        r, c = r + dr, c + dc
        k += 1
    return k
for r in range(1, 11):
    for c in range(1, 11):
        if a[r][c] == '.':
            h =  count(r, c - 1, 0, -1) + count(r, c + 1, 0, 1)
            v =  count(r - 1, c, -1, 0) + count(r + 1, c, 1, 0)
            u =  count(r + 1, c - 1, 1, -1) + count(r - 1, c + 1, - 1, 1)
            d =  count(r - 1, c - 1, -1, -1) + count(r + 1, c + 1, 1, 1)
            if h >= 4 or v >= 4 or u >= 4 or d >= 4:
                flag = True            
if flag == True:
    print('YES')
else:
    print('NO')