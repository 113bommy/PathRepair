def not_left(a, x):
    right = abs(x[-1] - a)
    left = abs(a - min(a, x[1]))
    print('not_left:', min(left, right) * 2 + max(left, right))
    return min(left, right) * 2 + max(left, right)

def not_right(a, x):
    right = abs(max(a, x[-2]) - a)
    left = abs(a - x[0])
    print('not_right:', min(left, right) * 2 + max(left, right))
    return min(left, right) * 2 + max(left, right)


n, a = map(int, input().split())
x = sorted(list(map(int, input().split())))
print(x)

if n == 1:
    print(0)
elif n == 2:
    if a <= x[0]:
        print(abs(x[0] - a))
    elif a >= x[1]:
        print(abs(a - x[1]))
    else:
        left = abs(a - x[0])
        right = abs(x[1] - a)
        print(min(left, right))

elif a >= x[-1]:
    print(abs(a - x[1]))
elif a <= x[0]:
    print(abs(x[-2] - a))
else:
    print(min(not_right(a, x), not_left(a, x)))
