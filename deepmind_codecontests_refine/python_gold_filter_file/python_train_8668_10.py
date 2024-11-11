import math
for _ in range(int(input())):
    x,y, k= map(int,input().split())
    print(( k+ k*y -1+ x-2)//(x-1) + k)
