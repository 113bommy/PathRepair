n = int(input())

from math import ceil

def get_min(a, b):
    if len(a) != len(b):
        return a if len(a) < len(b) and a != '' else b
    
    for i in range(len(a)):
        if a[i] != b[i]:
            return a if a[i] < b[i] else b

    return a

permutation = ''

for i in range((n // 7)+1):
    k = n - (i * 7)
    if k % 4 == 0:
        for _ in range(k // 4):
            print(4, end='')
        for _ in range(i):
            print(7, end='')
        
        exit()

print(-1)
