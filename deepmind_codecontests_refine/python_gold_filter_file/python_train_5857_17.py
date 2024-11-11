import math
n = int(input())
for w in range(n):
    a,b = map(int, input().split())
    x = min(a,b)
    s = (x*(x+1))//2
    if(b>=a):
        s=s-(x)+1
    print(s)