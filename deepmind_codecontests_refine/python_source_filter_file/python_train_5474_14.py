from sys import stdin, stdout
from math import ceil


def GCD(a, b):
    if not b:
        return a
    else:
        return GCD(b, a % b)


t = int(stdin.readline())
for i in range(t):
    x, y, p, q = map(int, stdin.readline().split())
    
    
    
    if (p / q == x / y):
        stdout.write('0\n')
        continue
    
    
    l = -1
    r = 10 ** 50
    
    while (r - l > 1):
        m = (r + l) // 2
        
        
        def check(m):
            if p * m >= x:
                a = p * m - x
                b = q * m - y - a
                
                if b < 0:
                    a = 0
                else:
                    a += b
                
                return a
            else:
                return 0
        
        
        if check(m):
            r = m
        else:
            l = m
    
    
    ans = check(r)
    
    if (not ans):
        stdout.write('-1')
    else:
        stdout.write(str(ans) + '\n')