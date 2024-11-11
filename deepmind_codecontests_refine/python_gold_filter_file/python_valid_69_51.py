t = int(input())


def common_sequence(a, powerOfTwo):
    a = str(a)
    powerOfTwo = str(powerOfTwo)
    potL = len(powerOfTwo)

    numSimilar = 0

    for i in a:
        if i == powerOfTwo[numSimilar]:
            numSimilar += 1

        if numSimilar == potL:
            break

    numToAdd = potL - numSimilar

    numToRemove = len(str(a)) - numSimilar

    return numToRemove + numToAdd


for i in range(t):
    n = int(input())

    powerOfTwo = 1

    ans = float('inf')
    for j in range(100):
        ans = min(common_sequence(n, powerOfTwo), ans)
        powerOfTwo *= 2
    ans = min(ans, len(str(n)) + 1)

    print(ans)
