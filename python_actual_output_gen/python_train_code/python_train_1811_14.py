import sys;input=sys.stdin.readline

T, = map(int, input().split())
for _ in range(T):
    a, b = map(int, input().split())
    if a*2 > b:
        print(-1)
    else:
        print(a, a*2)
