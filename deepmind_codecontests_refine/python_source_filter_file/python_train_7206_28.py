from math import ceil 

n = int(input())
for i in range(n):
    a,b,x,y = map(int, input().split())
    print(max(b*max(x-1, a-x), a*max(y-1, b-y)))