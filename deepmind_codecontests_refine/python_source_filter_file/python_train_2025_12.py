#author : dokueki

import sys
INT_MAX = sys.maxsize
INT_MIN = -(sys.maxsize)-1
sys.setrecursionlimit(10**5)
mod = 1000000007


def IOE():
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")


def main():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    inc = [a[0]]
    dec = []
    flag = False
    for i in range(n-1):
        if a[i + 1] > a[i] and not flag:
            inc.append(a[i + 1])
        else:
            flag = True
        if flag:
            dec.append(a[i + 1])
    if dec+inc == sorted(a):
        print(len(dec))
    else:
        print(-1)


if __name__ == "__main__":
    try:
        IOE()
    except:
        pass
    main()
