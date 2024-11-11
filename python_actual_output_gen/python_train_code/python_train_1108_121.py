a = input().split()
lim = int(a[0])
bob = int(a[1])
x = 0
while bob > lim:
    bob = bob * 2
    lim = lim * 3
    x += 1
print(x)
