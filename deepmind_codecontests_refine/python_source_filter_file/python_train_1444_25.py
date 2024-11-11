import sys

def f(b, n):
    if b < 2:
        return -1    

    if b > n:
        return n

    return f(b, n//b) + n % b


def main():
    input = sys.stdin.readline
    n = int(input())
    s = int(input())

    if s > n:
        return -1

    if s == n:
        return n+1

    for i in range(2, int(n**0.5)):
        if f(i, n) == s:
            return i

    for p in range(int(n**0.5), 0, -1):
        if (n - s) % p != 0:
            continue

        b = (n - s) // p + 1
        if f(b, n) == s:
            return b

    return -1


if __name__ == '__main__':
    print(main())
