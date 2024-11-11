# _1203c
#####################################################################################################################

from math import sqrt, ceil


def commonDivisorsOf(array):
    lowestValue = min(array)
    for factor in factorsOf(lowestValue):
        validFactor = testFactor(factor, array)
        if validFactor:
            return validFactor


def testFactor(factor, array):
    for value in array:
        if value%factor:
            return False

    return nFactorsOf(factor)


def factorsOf(n):
    if n == 1:
        yield 1
        return

    factorsStorage, squareRoot_n = [], sqrt(n)
    limit = ceil(squareRoot_n)
    for value in range(1, limit):
        if not n%value:
            yield n/value
            factorsStorage.append(value)

    if squareRoot_n == limit:
        yield limit

    factorsStorage.reverse()
    for factor in factorsStorage:
        yield factor


def nFactorsOf(n):
    if n == 1:
        return 1

    squareRoot_n = sqrt(n)
    limit = ceil(squareRoot_n)
    nFactors = sum(2 for value in range(1, limit) if not n%value)
    return nFactors + 1 if squareRoot_n == limit else nFactors


input()
print(commonDivisorsOf(map(int, input().split())))
