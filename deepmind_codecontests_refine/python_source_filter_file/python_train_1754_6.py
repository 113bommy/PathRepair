n, a, b, c, d = [int(item) for item in input().split()]

u, l = 0, 0
while n > 1:
    if b <= a + u + (n-1) * d and b >= a + l + (n-1) * c:
        print("YES")
        exit()
    if b >= a + u + (n-1) * -d and b <= a + l + (n-1) * -c:
        print("YES")
        exit()
    n -= 2
    u += d - c
    l -= d - c
print("NO")