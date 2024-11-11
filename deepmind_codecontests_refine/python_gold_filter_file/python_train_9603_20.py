import math

def main():
    a, b, c, d = [int(i) for i in input().split()]

    if b >= a:
        return b

    elif c <= d:
        return -1

    else:
        e = math.ceil((a-b)/(c-d))
        return b + c*e

for i in range(int(input())):
    print(main())
