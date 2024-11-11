from collections import defaultdict as df
import sys
input = lambda : sys.stdin.readline().rstrip()

t = int(input())
for _ in range(t):
    n,a,b = map(int, input().split())
    #n = int(input())
    arr = [int(i) for i in input()]
    #s = sum(arr)
    #remain = s%n
    #not_remain = n - remain
    #print(remain * not_remain)
    #s = list(input()
    cons_s = a*n
    cons_time = 0
    w = 0
    bl = 0
    if arr[0]:
        w += 1
    else:
        bl += 1
    for i in range(1, n):
        if arr[i] != arr[i - 1]:
            if arr[i]:
                w += 1
            else:
                bl += 1
    cons_time = min(bl,w) + 1
            
    
    
    if a >= 0 and b >= 0:
        print(n*b + n*a)
    elif a < 0 and b < 0:
        print(cons_time * b + n*a)
    elif a >= 0 and b < 0:
        print(n*a + cons_time * b)
    else:
        print(n*b + n*a)
        
            
    #print()
    
