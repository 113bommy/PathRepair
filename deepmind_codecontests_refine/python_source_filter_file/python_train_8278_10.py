import math

n, k = map(int, input().split())

recipe = [int(z) for z in input().split()]
inventory = [int(z) for z in input().split()]

m = 0
for i in range(n):
    m = max(m, math.ceil((inventory[i] + k) // recipe[i]))

onecookie = sum(recipe)
ans = 0
left = 0
right = m
oldc = 0
while left <= right:
    kneeded = 0
    c = (left + right) // 2
    if oldc == c:
        print(c)
        exit()
    for i in range(n):
        kneeded += max(0, recipe[i] * c - inventory[i])

    if kneeded == k:
        break
    elif kneeded > k:
        right = c
    elif kneeded < k:
        left = c

    oldc = c

    print(c, left, right, kneeded)

print(c)