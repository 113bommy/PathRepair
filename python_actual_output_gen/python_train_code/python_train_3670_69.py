def wrong_subtract(number, b):
    while b > 0:
        digit = number % 10
        if digit >= b:
            return number - b
        else:
            number //= 10
            b -= digit + 1
    return 0

a, b = map(int, input().split())
print(wrong_subtract(a, b))