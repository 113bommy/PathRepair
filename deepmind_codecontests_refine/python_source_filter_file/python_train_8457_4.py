import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if sorted(a) != a:
        if 0 not in b and 1 not in b:
            print('No')
            continue
    print('Yes')