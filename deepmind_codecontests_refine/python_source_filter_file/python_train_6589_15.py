import sys
from math import sqrt

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))


def s(d):
    dis = 1 + 4 * 2 * 3 * d
    ds = sqrt(dis)
    return (-1 + ds) / 6


def main():
    c = inp()
    d = list((map(int, insr())))
    print("YES" if sum(d[0:len(d)//2])==sum(d[len(d)//2:]) and [str(b) in "47" for b in d] else "NO")



if __name__ == "__main__":
    # sys.setrecursionlimit(10 ** 6)
    # threading.stack_size(10 ** 8)
    # t = threading.Thread(target=main)
    # t.start()
    # t.join()
    main()
