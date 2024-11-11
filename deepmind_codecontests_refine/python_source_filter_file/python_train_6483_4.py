import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    cur = 0
    turn = 0
    while n > 0:
        if turn == 0:
            if n % 4 == 0 and n > 8:
                cur += n-1
                n -= 1
            elif n % 2 == 0:
                cur += n // 2
                n //= 2
            else:
                cur += 1
                n -= 1
            turn = 1
        else:
            if n % 4 == 0and n > 8:
                n -= 1
            elif n % 2 == 0:
                n //= 2
            else:
                n -= 1
            turn = 0
    print(cur)