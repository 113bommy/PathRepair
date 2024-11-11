def check(a, b, c, d):
    if a > d and b > c:
        return 1
    return 0
a = [0 for i in range(4)]
b = [0 for i in range(4)]
for i in range(4):
    a[i], b[i] = map(int, input().split())
if check(a[0], b[1], a[2], b[3]) and check(a[0], b[1], a[3], b[2]):
    print('Team 1')
elif check(a[1], b[0], a[2], b[3]) and check(a[1], b[0], a[3], b[2]):
    print('Team 1')
elif (check(a[2], b[3], a[0], b[1]) or check(a[2], b[3], a[1], b[0])) and (check(a[3], b[2], a[0], b[1]) or check(a[3], b[2], a[1], b[0])):
    print('Team 2')
else:
    print('Draw')