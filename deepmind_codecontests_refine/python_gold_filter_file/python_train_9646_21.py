def solve():
    n = int(input())

    squares = set()
    j = 1
    while j * j <= 2 * 10 ** 9:
        squares.add(j * j)
        j += 1
    m = float('inf')
    for i in range(1, 2 ** len(str(n))):
        b = bin(i)[2:]
        x = '0' * (len(str(n)) - len(b)) + b
        z = ''.join([str(n)[i] for i in range(len(str(n))) if int(x[i])])
        if int(z) in squares and (len(z) == 1 or z[0] != '0'):
            m = min(m, x.count('0'))
    if m == float('inf'):
        return -1
    else:
        return m


print(solve())