import sys
# from itertools import permutations, combinations
# from collections import deque
# import math
# from bisect import bisect

# FAST INPUT for submit
# import io, os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input = sys.stdin.readline

# FAST OUTPUT for submit
#
#


def in1():
    return int(input())


def in3():
    return map(int, input().split())


def inx():
    return [int(_) for _ in input().split()]


t = in1()


def find_palindrome(cropped_string):
    smax = ""
    # len , current , type
    prog = []
    # len , type
    final = [0, 0]
    cur = 0

    while (cur < len(cropped_string)):
        prog2 = []
        # print(cur,prog,final)
        for i, x in enumerate(prog):
            h = x[1]
            # print("x",x)
            # print(cropped_string[h],cropped_string[cur])
            if h == -1:
                if final[0] < x[0] or (final[0] == x[0] and x[2] ==1):
                    final = [x[0],x[2]]


            elif cropped_string[h] == cropped_string[cur]:
                x[1] -= 1
                if x[1] == -1:
                    # print(f"final",x[0],final)
                    if final[0] < x[0] or (final[0] == x[0] and x[2] ==1):
                        final = [x[0],x[2]]
                else:
                    prog2.append(x)


        # abccba
        if cur > 0:
            if cropped_string[cur] == cropped_string[cur-1]:
                prog2.append([cur, cur-2, 0])
        # abcba
        if cur > 1:
            if cropped_string[cur] == cropped_string[cur-2]:
                prog2.append([cur-1, cur-3, 1])

        prog = prog2
        cur += 1
        # print(cropped_string[:cur])
        # print(cur, prog, final)
        # print("_"*22)

    # print(f"{final=}")
    
    olen = final [0] * 2 + final[1]

    return cropped_string[:olen]
    # return smax


for _ in range(t):

    s = input()
    r = s[::-1]

    i = 0
    while i < (len(s)//2):
        if s[i] == r[i]:
            i += 1
        else:
            break

    if i*2 == len(s):
        # print("ans")
        print(s)
        continue

    crop = s[i:len(s)-i]
    side = i

    # print(f"{crop=} {side=}")

    left = find_palindrome(crop)
    # print("_"*10)
    right = find_palindrome(crop[::-1])
    # print("left, right")
    # print(left,right)
    
    if not left and not right :
        mid = crop[0]
    elif len(left)>len(right):
        mid = left
    else:
        mid = right
    # print("ans")
    print(s[:i] +mid + s[:i][::-1])
