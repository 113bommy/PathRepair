import os

T = int(input())

for times in range(T):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    if(x == y and x == 0):
        print(0)
    elif(a*2 < b):
        print((abs(a) + abs(b))*a)
    elif(x*y > 0):
        little = min(abs(x), abs(y))
        ans = little * b + (max(abs(x), abs(y)) - little) * a
        print(ans)
    else:
        ans = (abs(x) + abs(y)) * a
        print(ans)