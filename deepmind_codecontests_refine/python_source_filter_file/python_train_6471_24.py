def sequence(n):
    s = ''
    for i in range(10000):
        s += str(i)
    return s[n - 1]


print(sequence(int(input())))
