from math import ceil 

n = int(input())
for i in range(n):
    a,b,x,y = map(int, input().split())
    print(max(b*max(x, a-x-1), a*max(y, b-y-1)))