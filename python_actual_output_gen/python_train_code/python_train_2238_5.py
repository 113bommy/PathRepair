input()
a = b = 0
for x, y in zip(input(), input()):
    a += x > y
    b += x < y
print(-1 if b==0 else a//b+1)