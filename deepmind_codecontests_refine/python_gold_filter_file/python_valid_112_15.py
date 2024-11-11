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
    # usage: m, n = input_int_gen()
    return map(int,input().split())


# Codeforce xxx Div x A
tests = inp()
for _ in range(tests):
    lst = input_list()
    m = lst[3]
    lst = sorted(lst[:3])
    c, b, a = lst[0], lst[1], lst[2]
    maxp = (a-1)+ (b-1) + (c-1)
    if m>maxp:
        print('NO')
        continue
    if a <= b+c+1:
         print('YES')
         continue
    else:
        if m < a - b - c - 1:
            print('NO')
            continue
    print('YES')