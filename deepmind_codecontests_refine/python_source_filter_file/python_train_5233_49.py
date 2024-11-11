from math import ceil
for _ in range(int(input())):
    a,b=map(int,input().split())
    if a>(b/2):
        print(-1,-1)
    else:
        print(a,b)
    