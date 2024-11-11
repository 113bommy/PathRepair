import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp(): 
    # one integer
    return int(input())
def input_list():
    # list of integers
    return list(map(int,input().split()))
def input_string():
    # list of characters
    s = input()
    return list(s[:len(s) - 1])
def input_int_gen():
    # integer generator 
    return map(int,input().split())


# Codeforce Deltix Round Summer 2021 C
tests = 1
for _ in range(tests):
    n = inp()
    a = input_list()
    stk = [[0, 0]]
    lefts = 0
    ret = 0
    for idx, x in enumerate(a):
        if idx % 2 == 0:
            lefts += x
        else:
            level = 0
            valid = lefts
            if x <= lefts:
                level = lefts - x
                valid = x
            ret += valid

            while stk[-1][0] > level:
                ret += stk[-1][1]
                stk.pop()
            if stk[-1][0] == level:
                ret += stk[-1][1]
                stk[-1][1] += 1
            else:
                stk.append([level, 1])
            if x > lefts:
                stk = [[0,0]]
            # print(stk)
            lefts = level
    print(ret)
