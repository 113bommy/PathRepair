def sequence(n):
    s = ''
    for i in range(1, 10001):
        s += str(i)
    return s[n - 1]


print(sequence(int(input())))
