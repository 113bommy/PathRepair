n, a, b = map(int, input().split())

if b > 0:
    for i in range(b):
        a += 1

        if a == n+1:
            a = n
else:
    for i in range(abs(b)):
        a -= 1

        if a == 0:
            a = n

print(a)
