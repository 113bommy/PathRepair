import math
for _ in range(int(input())):

    s,c,n = map(int,input().split())
    print(((n*c+n-1+s-2)//(s-1))+n)