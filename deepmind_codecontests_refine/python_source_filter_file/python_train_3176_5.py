def rangeXY(n):
    firstDigit = "1"
    Middles = "0" * (n - 1)

    return int(firstDigit + Middles)


def main():
    n, t = input().split(" ")
    n, t = int(n), int(t)

    divisible: bool = False

    TheNumber = rangeXY(n)

    while len(str(TheNumber)) == n:
        if(not TheNumber % 2):
            divisible = True
            break
        TheNumber += 1

    if(not divisible):
        print(-1)
    else:
        print(TheNumber)


main()
