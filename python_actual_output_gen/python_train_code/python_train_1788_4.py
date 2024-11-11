def power(a, b=5):
    if b == 0:
        return 1
    return a * power(a, b - 1)


def last_five(number):
    n = number // 10000 % 10 * 10000 + number // 100 % 10 * 1000 + number % 10 * 100 + number / 10 % 10 * 10 + number / 1000 % 10
    n1 = str(power(n, 5))
    return n1[-5:-1]


print(last_five(int(input())))
