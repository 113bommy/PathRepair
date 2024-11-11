from math import floor, ceil
s = input()
k = int(input())

def f(s):
    b = ''
    ret = 0
    for i in s:
        if i==b:
            b = ''
            ret += 1
            continue
        b = i
    return ret

b = f(s*2) - f(s*1)
c = f(s*3) - f(s*2)
print(b*floor(k/2) + c*ceil(k/2))