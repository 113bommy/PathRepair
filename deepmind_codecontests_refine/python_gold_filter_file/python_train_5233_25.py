import sys
input = sys.stdin.readline

for kek in range(int(input())):
    (l, r) = map(int, input().split())
    if l*2 > r:
        print(-1, -1)
    else:
        print(l, 2*l)