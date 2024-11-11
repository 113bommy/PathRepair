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

mem = [0]
def xors(n):
    if len(mem) > n:
        return mem[n]
    else:
        for i in range(len(mem), n+1):
            mem.append(mem[-1] ^ i)
        return mem[n]

# Codeforce 742 Div 2 B
from collections import Counter
tests = inp()
for _ in range(tests):
    n = inp()
    s = input_string()
    s = [int(x) for x in s]
    c = Counter(s)
    if 0 < c[2] < 3:
        print("NO")
    else:
        print("YES")
        if c[2] >= 3:
            a = s.index(2)
            b = len(s) - next(i for i, x in enumerate(reversed(s), 1) if x == 2)
        else:
            a = -1
            b = -1
        # print(a,b)
        for i in range(n):
            line = []
            for j in range(n):
                if i == j:
                    line.append("X")
                elif s[i] == 1 or s[j] == 1:
                    line.append("=")
                else:
                    if i == a and j == b:
                        line.append("+")
                    elif i == b and j == a:
                        line.append("-")
                    elif i < j:
                        line.append("-")
                    else:
                        line.append("+")
            print("".join(line))
