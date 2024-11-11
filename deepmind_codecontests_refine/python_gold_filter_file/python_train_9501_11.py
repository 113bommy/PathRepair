from collections import deque
import sys


def input():
    return sys.stdin.readline().rstrip()


def slv():
    n = int(input())
    G = [[] for i in range(n)]
    IN = [0]*(n)
    S = input()
    if S == "L"*n or S == "R"*n:
        print((n + 2)//3)
        return

    #no circle

    for i in range(n):
        l, r = i - 1, (i + 1) % n
        if S[i] == "R":
            G[i].append(r)
            IN[r] += 1
        else:
            G[i].append(l)
            IN[l] += 1

    ans = 0
    for i in range(n):
        if IN[i] == 0:
            l = 0
            p = i
            while IN[p] != 2:
                p = G[p][0]
                l += 1
            #print("IN, length", i, l)
            ans += (l + 1)//3
    print(ans)
    return


def main():
    t = int(input())
    for _ in range(t):
        slv()
    return


if __name__ == "__main__":
    main()
