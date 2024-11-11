def nod(a, b):
    a, b = min(a, b), max(a, b)
    while a > 0:
        a, b = b % a, a
    return b

n = int(input())
for i in range(n):
    r, b, k = [int(i) for i in input().split()]
    r, b = max(r, b), min(r, b)
    if (k - 1) * b + nod(b, r) >= r-1:
        print('OBEY')   
    else:
        print('REBEL')
