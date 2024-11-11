#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

def main():
    n, = readln()
    for _ in range(4):
        a, b, c, d = readln()
        a = min(a, b)
        c = min(c, d)
        if a + c <= n:
            print(_ + 1, a, n - a)
            return
    print(-1)

if __name__ == '__main__':
    main()
