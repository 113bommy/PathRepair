import sys,io,os
try: input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except: input = lambda: sys.stdin.readline().encode()
read = lambda: map(int,input().split())
from collections import defaultdict as dd
O = []
for _ in range(int(input())):
    n = int(input())
    s = list(map(chr,input().strip()))
    for i in range(n//2,n):
        if s[i]=='0':
            O.append(f'1 {i} 1 {i+1}')
            break
    else:
        if s[n//2-1]=='0': O.append(f'{n//2} {n} {n//2+1} {n}')
        else: O.append(f'{n//2} {n-1} {n//2+1} {n}')
print('\n'.join(O))