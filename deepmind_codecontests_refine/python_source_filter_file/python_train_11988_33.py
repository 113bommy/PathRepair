import math


def ii(): return int(input())


def ill(): return input().split(' ')


def ili(): return [int(i) for i in input().split(' ')]


def ilis(): return (int(i) for i in input().split(' '))


def gcd(a, b): return a if b == 0 else gcd(b, a % b)


def extgcd(a, b, x=0, y=0):
    if b == 0:
        return (a, 1, 0)
    d, m, n = extgcd(b, a % b, x, y)
    return (d, n, m-(a//b)*n)


b = [2, 3, 4, 5]


def isnum(n):
    global b
    if n in b:
        return True
    for i in range(n // 2):
        if isnum(i) and isnum(n - i):
            b.append(i)
            b.append(n - i)
            return True


def main():
    T = ii()
    # 2 3 4 5
    if T in (2, 3, 4, 5, 12, 30, 35, 43, 46, 52, 64):
        print('YES')
        exit(0)
    print('NO')


if __name__ == "__main__":
    main()
