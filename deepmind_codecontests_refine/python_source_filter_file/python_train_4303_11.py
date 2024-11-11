import math
def solve():
    a,b = map(int,input().split())
    if a>b:
        a,b = b,a
    x = abs(b-a)
    if a==b:
        print(0,0)
    else:
        if a==0:
            print(x,0)
        else:
            print(x,min(a%x,b-a%x))

t = int(input())
for _ in range(t):
    solve()