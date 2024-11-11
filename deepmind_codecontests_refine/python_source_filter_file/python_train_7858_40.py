n = int(input())
t = [int(x) for x in input().split()]
x = 0
c = 0
y = 0
for i in t:
    if i < x:
        y = max(y, c)
        c = 0

    c += 1
    x = i
print(y)
