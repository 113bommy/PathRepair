# robot

n, b, a = map(int, input().split(' '))
L = list(map(int, input().split(' ')))


def robot(a, b, L):
    def use_acc(a):
        a -= 1
        return a

    def use_bat(a, b, light):
        b -= 1
        if light:
            a += 1
        return a, b

    amax = a
    step = 0
    for i in range(n):
        if (a == 0 and b == 0):
            break
        elif a == 0:
            a, b = use_bat(a, b, L[i])
        elif b == 0:
            a = use_acc(a)
        elif (L[i] == 1 and a < amax):
            a, b = use_bat(a, b, L[i])
        else:
            a = use_acc(a)
        step = i

    return step

print(robot(a, b, L))