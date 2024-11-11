import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
t = int(input())
for case in range(t):
    n = int(input())
    # 2*3+2*5+2*7 = 30がmin
    if n >= 31:
        print("YES")
        if n - 30 in [6, 10, 14]:
            print(6, 10, 15, n - 31)
        else:
            print(6, 10, 14, n - 30)
    else:
        print("NO")

