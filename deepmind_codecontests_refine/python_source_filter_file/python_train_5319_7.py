p = 1e-6

def check(a, b, mass, val):
    m = mass + val
    m -= m/a[0]

    for i in range(1, len(a)):
        m -= m/b[i]
        m -= m/a[i]

    m -= m/b[0]
    return m >= mass

def search(a, b, mass, low, high):
    solved = False
    while(high - low >= p):
        mid = low + (high - low)/2
        if check(a, b, mass, mid):
            solved = True
            high = mid
        else:
            low = mid
    if solved:
        return high
    else:
        return -1

n = int(input())
mass = int(input())
a = [int(x) for x in input().strip().split()]
b = [int(x) for x in input().strip().split()]
print('{:0.10f}'.format(search(a, b, mass, 0, 1000000000+p)))
