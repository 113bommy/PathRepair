import sys
import math

#import os.path
#if os.path.isfile("input.txt"):
#    _file = open("input.txt")
#def readline():
#    return _file.readline();

def readline():
    return input()


def fun(n, a, b, c, s):
    ans = ["-"] * n
    w = 0
    for i in range(n):
        if s[i] == "R":
            if b > 0:
                b = b-1
                ans[i] = "P"
                w = w + 1
            else:
                ans[i] = "-"
        if s[i] == "P":
            if c > 0:
                c = c-1
                ans[i] = "S"
                w = w + 1
            else:
                ans[i] = "-"
        if s[i] == "S":
            if a > 0:
                a = a-1
                ans[i] = "R"
                w = w + 1
            else:
                ans[i] = "-"
    
    for i in range(n):
        if ans[i] == "-":
            if a > 0: ans[i] = "R"; a = a-1
            if b > 0: ans[i] = "P"; b = b-1
            if c > 0: ans[i] = "S"; c = c-1

    if w > math.ceil(n/2):
        print("YES")
        print("".join(ans))
    else:
        print("NO")
    

q = int(readline())
for i in range(q):
    n = int(readline())
    v = list(map(int, readline().split(' ')))
    s = readline()
    #c = list(map(int, readline().split(' ')))
    ans = fun(n, v[0], v[1], v[2], s)
    

