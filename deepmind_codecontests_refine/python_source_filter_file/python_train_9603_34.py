from math import ceil

t = int(input())
for i in range(t):
    a,b,c,d = list(map(int, input().split()))

    if b>=a:
        print(1)
    elif c <= d:
        print(-1)
    else:
        ans = c-d
        ans = ceil((a-b)/ans)
        print(b+(ans*c))






