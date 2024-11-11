n, m = map(int, input().split())
x, counter = m // n, 0
while x % 3 == 0:
    x, counter = x // 3, counter + 1
while x % 2 == 0:
    x, counter = x // 2, counter + 1
print(counter if x == 1 else -1)
