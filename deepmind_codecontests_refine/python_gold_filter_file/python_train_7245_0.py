a = ['$'*12] 
for i in range(10):
    a.append('$' + input() + '$')
a.append('$'*12)

def count(r, c, dr, dc):
    k = 0
    while a[r][c] == 'X':
        k += 1
        r += dr 
        c += dc
    return k
f = 0
for i in range(1,11):
    if f == 1:
        break
    for j in range(1, 11):
        if a[i][j] == '.':
            h = count(i, j-1, 0, -1) + count(i, j+1, 0, 1)
            v = count(i+1, j, 1, 0) + count(i-1, j, -1, 0)
            d1 = count(i-1, j-1, -1, -1) + count(i+1, j+1, 1, 1)
            d2 = count (i+1, j-1, 1, -1) + count(i-1, j+1, -1, 1)
            if h >= 4 or v >= 4 or d1 >= 4 or d2 >= 4:
                print('YES')
                f = 1
                break
if f == 0:
    print('NO')
        
                

            
        
    