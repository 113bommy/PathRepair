import math

n, m = map(int, input().split(" "))

start = 1
end = n

wq = n // 4
for i in range(m):
    if i == wq and i % 2 == 0:
        start += 1
    print(start, end)
    start += 1
    end -= 1