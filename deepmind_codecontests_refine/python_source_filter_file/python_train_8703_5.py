l, r, x, y, k = map(int, input().split())

X = (l + k - 1) // k
Y = r // k
if X <= Y and x <= X <= y or y <= Y <= y or X <= x <= Y or X <= y <= Y:
    print('YES')
else:
    print('NO')