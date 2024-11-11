import math

def main():
    n = input()
    ns = [int(x) for x in input().split(' ')]

    res = 0
    neg = 0
    hasZero = False
    for x in ns:
        if x > 0:
            res += x - 1
        elif x < 0:
            res += -1 - x
            neg += 1
        else:
            res += 1
            has_zero = True

    if hasZero:
        print(res)
    elif neg % 2 == 0:
        print(res)
    else:
        print(res + 2)

if __name__ == '__main__':
    main()

