'''
Created on 2016-4-18

@author: chronocorax
'''
def line(): return [int(s) for s in input().split()]
n, d, h = line()

if d >= h and d <= 2 * h and n >= d + 1 and not (n > 2 and d == 1 and h == 1):
    
    for i in range(1, h + 1):
        print(i, i + 1)
    
    root = 1
    s = d - h
    if s == 0:
        s = 1
        root = 2
    
    ch = 0
    i = h + 2
    while i <= n:
        ch = ch % s
        if ch == 0: print(root, i)
        else: print(i - 1, i)
        ch += 1
        i += 1
else:
    print(-1)
    