n = int(input())
s = input()
c0, c1, c2 = 0, 0, 0
for x in s:
    if x == '0':
        c0 += 1
    elif x == '1':
        c1 += 1
    elif x == '2':
        c2 += 1
r = n // 3
#print(c0, c1, c2)

need = abs(r - c0) + abs(r - c1) + abs(r - c2)
need //= 2
#print(need)

ar = [x for x in s]

if c0 < r:
    for x in range(n):
        #print(''.join(ar))
        if ar[x] == '1' and c1 > r:
            c0 += 1
            c1 -= 1
            ar[x] = '0'
        elif ar[x] == '2' and c2 > r:
            c0 += 1
            c2 -= 1
            ar[x] = '0'
        #print(''.join(ar))
        #print('-' * 10)
        if c0 == r:
            break
        

if c2 < r:
    for x in range(n - 1, -1, -1):
        #print(''.join(ar))
        if ar[x] == '1' and c1 > r:
            c2 += 1
            c1 -= 1
            ar[x] = '2'
        elif ar[x] == '0' and c0 > r:
            c2 += 1
            c0 -= 1
            ar[x] = '2'
        #print(''.join(ar))
        #print('-' * 10)
        if c2 == r:
            break


if c2 > r:
    for x in range(n):
        #print(''.join(ar))
        if ar[x] == '2':
            c1 += 1
            c2 -= 1
            ar[x] = '1'
        #print(''.join(ar))
        #print('-' * 10)
        if c0 == r:
            break
if c0 > r:
    for x in range(n - 1, -1, -1):
        #print(''.join(ar))
        if ar[x] == '0':
            c1 += 1
            c0 -= 1
            ar[x] = '1'
        #print(''.join(ar))
        #print('-' * 10)
        if c0 == r:
            break

print(''.join(ar))

