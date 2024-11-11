'''
     |\_/|                  
     | @ @   Woof! 
     |   <>              _  
     |  _/\------____ ((| |))
     |               `--' |   
 ____|_       ___|   |___.' 
/_/_____/____/_______|

I am here to gaurd this code, woof!

'''

from sys import stdin, stdout
from math import ceil, floor, sqrt, log, log2, log10
from collections import Counter

input = stdin.readline

def solve():
    pass

t = int(input())
# t = 1

for _ in range(t):
    # n = int(input())
    n, w = map(int, input().split())
    # s = input()
    # t = input()
    arr = list(map(int, input().split()))
    items = []
    for i in range(n):
        items.append([arr[i], i + 1])
    items.sort()
    total = 0
    output = []
    for i in range(n-1, -1, -1):
        if  total + items[i][0] <= w:
            total += items[i][0]
            output.append(items[i][1])

    output.sort()
    if len(output) > 0 and total >= w//2:
        print(len(output))
        print(*output)
    else:
        print(-1)
