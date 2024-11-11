import math

def solve(s, n, a, b):
    s = list(s)
    for i in s:
        if i == '0':
            a -= 1
        elif i == '1':
            b -= 1
    for i in range(n//2):
        if s[i] == '?' and s[-i-1] != '?':
            s[i] = s[-i-1]
            if s[i] == '0':
                a -= 1
            else:
                b -= 1
        elif s[i] != '?' and s[-i-1] == '?':
            s[-i-1] = s[i]
            if s[i] == '0':
                a -= 1
            else:
                b -= 1

    for i in range(n//2):
        if s[i] == s[-i-1] == '?':
            if a >= b:
                s[i] = '0'
                s[-i-1] = '0'
                a -= 2
            else:
                s[i] = '1'
                s[-i-1] = '1'
                b -= 2

    if n%2 != 0 and s[n//2] == '?':
        if a >= b:
            s[n//2] = '0'
            a -= 1
        else:
            s[n//2] = '1'
            b -= 1

    for i in range(n//2):
        if s[i] != s[-i-1]:
            return -1

    if a != b != 0:
        return -1

    return ''.join(s)

t = int(input())
for _ in range(t):
    a, b = [int(i) for i in input().split()]
    s = input()
    print(solve(s, a+b, a, b))


