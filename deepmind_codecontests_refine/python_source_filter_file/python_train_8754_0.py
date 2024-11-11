from sys import stdout
from random import randint

def search(l, r, k, n):
    flag = True
    while l != r or flag:
        flag = False
        if r - l <= 4*k + 2:
            pick = randint(l, r)
            print(pick, pick, sep=' ')
            stdout.flush()
    
            answer = input().strip()
            
            if answer == 'Yes':
                return
            elif answer == 'No':
                l = max(l - k, 0)
                r = min(r + k, n)
            continue
        
        m = (l + r) // 2
        print(l + 1, m, sep=' ')
        stdout.flush()
    
        answer = input().strip()
    
        if answer == 'Yes':
            if l + 1 == m:
                return
            l = max(l - k, 0)
            r = min(m + k, n)
            continue
        elif answer == 'No':
            l = max(m - k, 0)
            r = min(r + k, n)
        

n, k = map(int, input().split())

search(0, n, k, n)
