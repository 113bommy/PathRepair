#f = open('test.in', 'r')
#A = f.read().split()


t = int(input())
for i in range(t):
    A = input().split()
    a, b, c = [int(x) for x in A]
    if b < a:
        a, b = b, a
    if c < a:
        a, c = c, a
    if b > c:
        b, c = c, b
    if a == c:
        print(0)
        continue
    elif a == b:
        a += 1
        b += 1
        c = max(c - 1, a)
    elif b == c:
        b -= 1
        c -= 1
        a = min(a + 1, c)
    else:
        a += 1
        c -= 1
    print(2 * (c - a))
