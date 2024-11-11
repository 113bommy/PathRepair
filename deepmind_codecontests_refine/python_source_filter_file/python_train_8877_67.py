from math import ceil
try:
    t = int(input())
    for i in range(t):
        a,b,c,d=map(int,input().split())
        print(ceil((a+b+c+d)/2))
except:
    pass