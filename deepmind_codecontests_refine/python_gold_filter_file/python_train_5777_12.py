import sys
import time
import itertools
import math

def inp():
    ln = input().split()
    return int(ln[0]) if len(ln)==1 else [int(i) for i in ln]

def pr(x):
    if isinstance(x, list): print(' '.join([str(i) for i in x]))
    else: print(x)

def finish(x):
    pr(x)
    sys.exit()

# s = input()
# thing = 'Bulbasaur'*100000
# i=0
# for j in s:
#     if thing[i]==j: i+=1
#
# print(i//10)
# print(min(s.count('B'),s.count('u'),s.count('l'),s.count('b'),s.count('a')//2,s.count('s'),s.count('u'),s.count('r')))
# Problem A

# n = inp()
# a = []
# i=1
# while i<=n:
#     a.append(i)
#     i+=2
# i=2
# while i<=n:
#     if abs(i-a[-1])!=1:
#         a.append(i)
#     i += 2
# print(len(a))
# print(' '.join([str(i) for i in a]))

n = inp()
a = []
if n==1:
    print(1)
    print(1)
elif n==2:
    print(1)
    print(1)
elif n==4:
    print(4)
    print('2 4 1 3')
else:
    i=1
    while i<=n:
        a.append(i)
        i+=2
    i=2
    while i<=n:
        if abs(i-a[-1])!=1:
            a.append(i)
        i += 2
    print(len(a))
    print(' '.join([str(i) for i in a]))

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem B

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem C

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem D

# testcases = inp()
#
# for testcase in range (testcases):
#


# Problem E

# testcases = inp()
#
# for testcase in range (testcases):
#
