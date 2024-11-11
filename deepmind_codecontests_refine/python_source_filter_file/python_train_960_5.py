def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


for _ in range(int(input())):
    a, b, q = tuple(map(int, input().split()))
    a, b = min(a, b), max(a, b)
    nok = a * b / gcd(a, b)

    answers = []
    for _ in range(q):
        left, right = tuple(map(int, input().split()))

        delta = 0
        if left % nok != 0:
            ost = left % nok
            left -= ost

            delta += max(ost - b, 0)
        if right % nok != nok - 1:
            ost = right % nok
            right += (nok - ost - 1)

            if ost >= b:
                delta += nok - ost - 1
            else:
                delta += nok - b

        answers.append(int((right - left + 1) - delta - ((right - left + 1) // nok) * b))

    print(*answers)
