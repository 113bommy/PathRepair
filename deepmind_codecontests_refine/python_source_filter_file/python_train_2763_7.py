n = int(input())
number = input()

up = {1, 2, 3}
down = {7, 8, 9}
left = {1, 4, 7}
right = {3, 6, 9}

u, d, l, r = False, False, False, False

for i in number:
    i = int(i)
    if i in up:
        u = True
    if i in down:
        d = True
    if i in left:
        l = True
    if i in right:
        r = True

if (u and '0' in number) or (u and d and l and r):
    print('YES')
else:
    print('NO')
