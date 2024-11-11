def arr_inp():
    return [int(x) for x in input().split()]


n, s = int(input()), input()
a = arr_inp()
m, c1 = 10 ** 9 + 1, 0

while (s.find('RL', c1, -1) != -1):
    ix = s.find('RL', c1, -1)
    m = min(m, (a[ix + 1] - a[ix]) // 2)
    c1 =ix+2

if (c1 == 0):
    exit(print(-1))
print(m)
