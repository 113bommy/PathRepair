m, n = map(int, input().split())
while m != 0 and n != 0:
    if m >= 2 * n:
        m = m % (2*n)
    elif  m >= 2 * n:
        n = n % (2*m)
    else:
        break
print(m, n)

