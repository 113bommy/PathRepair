import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, x = map(int, input().split())
    b = [0] * 222
    for i in map(int, input().split()):
        b[i] = 1
    ans = 0
    for i in range(1, 222):
        if b[i]:
            ans += 1
        elif x:
            x -= 1
            ans += 1
        else:
            break
    print(ans)

