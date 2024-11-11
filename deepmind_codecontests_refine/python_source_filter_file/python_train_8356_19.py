import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().rstrip().split())
inl = lambda: list(map(int, input().split()))
out = lambda x, s='\n': print(s.join(map(str, x)))

t = ini()
for _ in range(t):
    n = ini()
    ans = False
    for i in range(1, 6):
        if n - 3 * i > 0 and (n - 3 * i) % 5 == 0:
            print(i, (n - 3 * i) // 5, 0)
            ans = True
            break
        if n - 7 * i > 0 and (n - 7 * i) % 5 == 0:
            print(0, (n - 7 * i) // 5, i)
            ans = True
            break
    if not ans:
        print(-1)