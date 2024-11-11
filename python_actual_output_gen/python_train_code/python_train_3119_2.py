def f(n):
    def toTri(x):
        if x <= 2:
            return [x]
        l = toTri(int(x / 3))
        l.append(x % 3)
        return l

    digits = toTri(n)
    for i in range(len(digits) - 1, -1, -1):
        if digits[i] != 0:
            break
    coins = 1
    mul = 1
    for j in range(i - 1, -1, -1):
        coins += mul * digits[j]
        mul *= 3
    return coins

n = int(input())
print(f(n))

