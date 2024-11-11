

input=__import__('sys').stdin.readline

for _ in range(int(input())):
    n = int(input())
    ans = 0
    c = 1
    while n:
        r = 0
        if n %2 == 0 and n// 2%3  or n == 4:
            n //= 2
            r = n
        else:
            r = 1
            n -= 1
        if c:
            ans += r
        c ^= 1
    print(ans)
    