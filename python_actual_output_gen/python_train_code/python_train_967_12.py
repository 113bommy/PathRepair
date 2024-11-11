def transpose(p, i, j):
    if p != i and p != j:
        return p
    else:
        return i if p == j else j
        
def cycle(p, n):
    return (p + n) % 3

def f(m, p):
    if m == 0:
        return p
    elif m == 1:
        return transpose(p, 0, 1)
    elif m == 2:
        return cycle(p, 2)
    elif m == 3:
        return transpose(p, 0, 2)
    elif m == 4:
        return cycle(p, 1)
    elif m == 5:
        return transpose(1, 2)

n = int(input())
p = int(input())

m = n % 6

print(f(m, p))


