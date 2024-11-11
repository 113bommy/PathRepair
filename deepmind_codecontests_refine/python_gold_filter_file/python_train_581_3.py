s = list(input())
a = list(map(int, s[:3]))
b = list(map(int, s[3:]))
p = sum(a)
q = sum(b)
if p == q:
    print(0)
elif p > q:
    diff = p - q
    num1 = 0
    b = sorted(b)
    a = sorted(a, reverse=True)
    diff -= 9 - b[0]
    if diff <= 0:
        num1 = 1
    else:
        diff -= 9 - b[1]
        if diff <= 0:
            num1 = 2
        else:
            num1 = 3

        diff = p - q - (9 - b[0])
        diff -= a[0]
        if diff <= 0:
            num1 = min(num1, 2)
        else:
            num1 = min(num1, 3)

    diff = p - q
    diff -= a[0]
    if diff <= 0:
        num2 = min(1, num1)
    else:
        diff -= a[1]
        if diff <= 0:
            num2 = min(2, num1)
        else:
            num2 = min(3, num1)

        diff = p - q - a[0]
        diff -= 9 - b[0]
        if diff <= 0:
            num2 = min(num2, 2)
        else:
            num2 = min(num2, 3)
    print(num2)

else:
    diff = q - p
    num1 = 0
    a = sorted(a)
    b = sorted(b, reverse=True)
    diff -= 9 - a[0]
    if diff <= 0:
        num1 = 1
    else:
        diff -= 9 - a[1]
        if diff <= 0:
            num1 = 2
        else:
            num1 = 3

        diff = q - p - (9 - a[0])
        diff -= b[0]
        if diff <= 0:
            num1 = min(num1, 2)
        else:
            num1 = min(num1, 3)

    diff = q - p
    diff -= b[0]
    if diff <= 0:
        num2 = min(1, num1)
    else:
        diff -= b[1]
        if diff <= 0:
            num2 = min(2, num1)
        else:
            num2 = min(3, num1)

        diff = q - p - b[0]
        diff -= 9 - a[0]
        if diff <= 0:
            num2 = min(num2, 2)
        else:
            num2 = min(num2, 3)

    print(num2)