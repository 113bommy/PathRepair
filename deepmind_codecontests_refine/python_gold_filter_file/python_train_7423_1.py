import sys,functools,collections,bisect,math,heapq
input = sys.stdin.readline
#print = sys.stdout.write
sys.setrecursionlimit(200000)
mod = 10**9 + 7

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    
    if s[0] == '0' or s[-1] == '0':
        print('NO')
        continue
    
    d = collections.Counter(s)
    
    if d['0']%2 or d['1']%2:
        print('NO')
        continue
    
    res1 = [1]*n
    res2 = [1]*n
    
    
    x = d['1']//2
    i = 0
    while x:
        if s[i] == '1':
            res1[i] = '('
            res2[i] = '('
            x -= 1
        i += 1
        if x == 0:
            while i < n:
                if s[i] == '1':
                    res1[i] = ')'
                    res2[i] = ')'
                i += 1
                
    c = 0
    for i in range(n):
        if s[i] == '0':
            if c%2:
                res1[i] = ')'
                res2[i] = '('
            else:
                res1[i] = '('
                res2[i] = ')'
            c += 1
    
    print('YES')
    print(''.join(res1))
    print(''.join(res2))
    
     