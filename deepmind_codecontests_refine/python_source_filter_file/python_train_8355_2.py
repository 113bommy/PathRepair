import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().rstrip().split())
inl = lambda: list(map(int, input().split()))
out = lambda x, s='\n': print(s.join(map(str, x)))

t = ini()
for _ in range(t):
    n, x, y = inm()
    dif = y - x
    ans = 0
    for i in range(1, dif+1):
        if dif % i != 0:
            continue
        count = n - 1
        tmp = y
        ok = False
        while count > 0 and tmp > 0:
            tmp -= i
            count -= 1
            if tmp == x:
                ok = True
        if tmp < 0:
            tmp += i
        if ok:
            # print(tmp, i)
            break
    numbers = []
    for j in range(0, n):
        numbers.append(tmp + i*j)
    out(numbers, " ")