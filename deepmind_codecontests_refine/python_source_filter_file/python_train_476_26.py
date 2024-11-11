s, v1, v2, t1, t2 = map(int, input().split())
a = 2 * t1 + v1 * s
b = 2 * t2 + v2 * s
if a == b:
    print('Friendship')
elif a > b:
    print('First')
else:
    print('Second')