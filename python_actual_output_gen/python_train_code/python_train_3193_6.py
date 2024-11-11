n = int(input())
sp = list(map(int, input().split()))
sp.sort()
l = 0
r = n
x, y = 0, 0
count = 0
while l != r:
    if count == 1:
        r -= 1
        x += sp[r]
        count = 0
    else:
        count = 1
        y += sp[l]
        l += 1
print(x ** 2 + y ** 2)