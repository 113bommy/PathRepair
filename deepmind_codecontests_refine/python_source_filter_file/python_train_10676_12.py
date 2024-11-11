from sys import stdin, stdout, stderr
import math

n = int(stdin.readline())

def go(lvl: int, cur: int, l: list):
    if (cur % lvl != 0):
        return False

    if(lvl == n + 1):
        return True

    for dx in range(0, 100000):
        cur += dx * lvl
        if(cur % lvl != 0):
            cur -= dx * lvl
            return False

        x = int(math.sqrt(cur))
        if(x * x == cur):
            l.append(dx)
            if(go(lvl + 1, x, l)):
                return True
            l.pop()
        cur -= dx * lvl

def main():
    cur = 2
    for lvl in range(1, n+2):
        stdout.write("2\n" if (lvl == 1) else str(lvl*(lvl+1)*(lvl+1) - lvl+1) + '\n')


if __name__ == '__main__':
    main()
