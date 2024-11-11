def get_gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


for test_i in range(int(input())):
    a, b, q = map(int, input().split())
    gcd = get_gcd(a, b)
    dx = a // gcd * b
    c = dx - max(a, b)
    ans = []
    for qi in range(q):
        l, r = map(int, input().split())
        if c > 0:
            max_x = r // dx
            min_x = (l - 1) // dx + 1
            if max_x < min_x:
                ans.append(min(max(r - max_x * dx + 1 - max(a, b), 0), r - l + 1))
            else:
                ans.append(c * (max_x - min_x) + min(min_x * dx - l, c) + max(r - max_x * dx + 1 - max(a, b), 0))
        else:
            ans.append(0)
    print(*ans)