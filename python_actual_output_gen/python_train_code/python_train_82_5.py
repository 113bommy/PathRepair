import sys
for _ in range(int(input())):
    n = int(input())
    if n == 1 :
        a,b = map(int, input().split())
        print(0)
        continue
    else:
        Min = sys.maxsize
        Max = - sys.maxsize - 1 
        for _ in range(n):
            a,b = map(int, input().split())
            Min = min(Min,b)
            Max = max(Max,a)
        
    print(Max-Min)
        