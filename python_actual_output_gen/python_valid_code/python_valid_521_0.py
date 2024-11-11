import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m = map(int,input().split())

    m += 1
    ans = 0
    b = 0

    while 1 << (b+1) < max(n,m):
        b += 1

    for i in range(b,-1,-1):
        if n>>i&1 and m>>i&1^1:
            break
        elif n>>i&1^1 and m>>i&1:
            ans |= 1 <<i

    print(ans)