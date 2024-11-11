#!/usr/bin/env python
'''
' Author:   Cheng-Shih Wong
' Email:    mob5566@gmail.com
' Date:     2017-08-02
'''

import re
from collections import deque

# compare the priority of operators
def comp(opa, opb):
    if opa=='(' or opb=='(':
        return False
    elif opa==')':
        return opb=='('
    elif opa in '*/':
        return opb in '+-*/)'
    else:
        return opb in '+-)'

# # print the operator priority table
# print('{:6}'.format(''), end='')
# for a in '+-*/()':
    # print('{:>6}'.format(a), end='')
# print()
# for a in '+-*/()':
    # print('{:>6}'.format(a), end='')
    # for b in '+-*/()':
        # print('{:6}'.format(comp(a, b)), end='')
    # print()

def arith(stk, stkop):
    B = stk.pop()
    A = stk.pop()
    op = stkop.pop()

    ok = True

    if op=='-' and B<2:
        ok = False
    elif op=='*' and (A<2 or B<2):
        ok = False
    elif op=='/' and (A<2 or B<3):
        ok = False

    if op in '+-':
        stk.append(1)
    elif op in '*/':
        stk.append(2)

    return ok

def solve(pri, exp, defs):
    terms = re.findall(r'[a-zA-z0-9]+|[\+\-\*/\(\)]', exp)
    safe = True

    # arithmetic
    stk = deque()
    opstk = deque()

    for term in terms:
        if term in '+-*/()':
            while len(opstk) and comp(opstk[-1], term):
                safe &= arith(stk, opstk)
            if term==')':
                opstk.pop()
                stk.pop()
                stk.append(3)
            else:
                opstk.append(term)
        else:
            if term not in pri:
                if term in defs:
                    ok, p = solve(pri, defs[term], defs)
                    safe &= ok
                    pri[term] = p
                else:
                    pri[term] = 3
            stk.append(pri[term])

    if len(opstk):
        safe &= arith(stk, opstk)

    return safe, stk.pop()

n = int(input())

inputs = [input() for i in range(n)]
expr = input()

defs = {}

for line in inputs:
    line = line[re.match(r'.*#.*define', line).end():]

    terms = re.findall(r'[^ ]+', line)
    defs[terms[0]] = ''.join(terms[1:])

prio = {}

if solve(prio, expr, defs)[0]:
    print('OK')
else:
    print('Suspicious')
