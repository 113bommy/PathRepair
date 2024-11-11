n = int(input())

c = 3
a = 1
b = 2

ans = "NO"

for i in range(n):
    x = int(input())

    if x == c:
        ans = "YES"

    if x == a:
        b, c = c, b
    elif x == b:
        a, c = c, a

print(ans)
