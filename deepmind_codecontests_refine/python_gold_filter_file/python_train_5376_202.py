# x, y = map(int, input().split())
# x1, y1 = map(int, input().split())

n = int(input())
m = int(input())

b = 2
i = 0

while m >= b:
    b *= 2
    i += 1

if n > i:
    print(m)
else:
    print(m % 2**n)
