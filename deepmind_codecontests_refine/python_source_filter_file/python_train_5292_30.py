import math

n = int(input())
c = -1
sum_ = 0
for i in range(n):
    a, b = map(int, input().split())
    sum_ += a
    if a > b:
        if c == -1:
            c = b
        if b > c:
            c = b
if c == -1:
    print("0")
else:
    print(s - c)
