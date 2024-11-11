from sys import stdin, stdout
from math import sin, tan, cos


def ask(i, j):
    stdout.write(str(i) + ' ' + str(j) + '\n')
    stdout.flush()
    return stdin.readline().strip()


T = int(stdin.readline())
for t in range(T):
    n = int(stdin.readline())
    
    if n == 1:
        stdout.write('! 1 1\n')
        stdout.flush()
        continue
    
    l, r = 1, 2
    if ask(l, r) == '>':
        l, r = r, l
    
    for i in range(3, n + 1, 2):
        if i == n:
            s = ask(l, i)
            f = ask(r, i)
            
            if s == '>':
                l = i
            
            if f == '<':
                r = i
            
            continue
        
        
        lb, rb = i, i + 1
        if ask(lb, rb) == '>':
            lb, rb = rb, lb
            
        
        if ask(lb, l) == '<':
            l = lb
        
        if ask(rb, r) == '>':
            r = rb

    stdout.write('! ' + str(l) + ' ' + str(r) + '\n')
    stdout.flush()