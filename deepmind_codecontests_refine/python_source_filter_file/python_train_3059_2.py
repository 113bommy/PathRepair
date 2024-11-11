p = int(input())

def f(x, p):
    y = 1
    for i in range(p - 2):
        y = (y * x) % p
        if y == 1: return False
    return (y * x) % p == 1

print(sum(f(x, p) for x in range(2, p)))