import sys

#sys.stdin = open("in.txt")
#sys.stdout = open("out.txt", "w")


def task():
    a1_res = 0
    d_res = 0

    n, x, y = map(int, input().split())
    p = y - x
    for d in range(1, p + 1):
        l = int(p / d)
        if l * d == p and l < n:
            a1 = y - (n-1) * d
            if a1 < 0:
                a1 = a1 + int((d - a1) / d) * d
            if a1_res == 0 or a1 + (n-1) * d < a1_res + (n-1) * d_res:
                a1_res = a1
                d_res = d
    return " ".join(map(str, range(a1_res, a1_res + (n-1) * d_res + 1,d_res)))


n = int(input())
for i in range(n):
    print(task())