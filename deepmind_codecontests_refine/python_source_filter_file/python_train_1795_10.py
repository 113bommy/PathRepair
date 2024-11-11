import math

def f(t) -> float:
    return math.sqrt(abs(t)) + 5 * t ** 3

a = [float(input()) for _ in range(11)]
for i, t in reversed(list(enumerate(a))):
    y = f(t)
    if y > 400:
        print('f(%.0f) =' % t, 'MAGNA NIMIS!')
    else:
        print('f(%.0f) =' % t, y)