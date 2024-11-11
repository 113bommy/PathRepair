import sys
import collections


sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N = int(input())
    XYU = [[x for x in input().split()] for _ in range(N)]

    ans = float("inf")

    c1 = collections.defaultdict(list)
    c2 = collections.defaultdict(list)

    for x, y, u in XYU:
        x = int(x)
        y = int(y)
        if u in ("U", "D"):
            c1[x].append([y, u])
        if u in ("U", "R"):
            c2[x + y].append([y, u])

    for k in c1.keys():
        c1[k].sort()
        tmp = -float("inf")
        for y, u in c1[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.2)
                    break

    for k in c2.keys():
        c2[k].sort()
        tmp = -float("inf")
        for y, u in c2[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.1)
                    break

    XYU2 = []
    for x, y, u in XYU:
        x = int(x)
        y = int(y)
        if u == "R":
            XYU2.append([y, -x, "D"])
        elif u == "L":
            XYU2.append([y, -x, "U"])
        elif u == "D":
            XYU2.append([y, -x, "L"])
        else:
            XYU2.append([y, -x, "R"])

    c1 = collections.defaultdict(list)
    c2 = collections.defaultdict(list)
    for x, y, u in XYU2:
        x = int(x)
        y = int(y)
        if u in ("U", "D"):
            c1[x].append([y, u])
        if u in ("U", "R"):
            c2[x + y].append([y, u])

    for k in c1.keys():
        c1[k].sort()
        tmp = -float("inf")
        for y, u in c1[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.2)
                    break

    for k in c2.keys():
        c2[k].sort()
        tmp = -float("inf")
        for y, u in c2[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.1)
                    break

    XYU3 = []
    for x, y, u in XYU2:
        x = int(x)
        y = int(y)
        if u == "R":
            XYU3.append([y, -x, "D"])
        elif u == "L":
            XYU3.append([y, -x, "U"])
        elif u == "D":
            XYU3.append([y, -x, "L"])
        else:
            XYU3.append([y, -x, "R"])

    c1 = collections.defaultdict(list)
    c2 = collections.defaultdict(list)
    for x, y, u in XYU3:
        x = int(x)
        y = int(y)
        if u in ("U", "D"):
            c1[x].append([y, u])
        if u in ("U", "R"):
            c2[x + y].append([y, u])

    for k in c1.keys():
        c1[k].sort()
        tmp = -float("inf")
        for y, u in c1[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.2)
                    break

    for k in c2.keys():
        c2[k].sort()
        tmp = -float("inf")
        for y, u in c2[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.1)
                    break

    XYU4 = []
    for x, y, u in XYU3:
        x = int(x)
        y = int(y)
        if u == "R":
            XYU4.append([y, -x, "D"])
        elif u == "L":
            XYU4.append([y, -x, "U"])
        elif u == "D":
            XYU4.append([y, -x, "L"])
        else:
            XYU4.append([y, -x, "R"])

    c1 = collections.defaultdict(list)
    c2 = collections.defaultdict(list)
    for x, y, u in XYU3:
        x = int(x)
        y = int(y)
        if u in ("U", "D"):
            c1[x].append([y, u])
        if u in ("U", "R"):
            c2[x + y].append([y, u])

    for k in c1.keys():
        c1[k].sort()
        tmp = -float("inf")
        for y, u in c1[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.2)
                    break

    for k in c2.keys():
        c2[k].sort()
        tmp = -float("inf")
        for y, u in c2[k]:
            if u == "U":
                tmp = y
            else:
                if tmp != -float("inf"):
                    ans = min(ans, (y - tmp) / 0.1)
                    break

    if ans == float("inf"):
        print("SAFE")
    else:
        print(int(ans))





    

if __name__ == '__main__':
    main()

