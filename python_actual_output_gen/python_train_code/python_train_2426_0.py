n, m = map(int, input().split())

a = 1
b = 1
t = 0

while a * a <= n:
        if a + (n - a * a) ** 2 == m:
            t += 1
        a += 1

print(t)



