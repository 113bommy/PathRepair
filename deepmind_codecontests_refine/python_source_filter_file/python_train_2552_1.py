n = int(input())
lst = list(map(int, input().split()))
lst.sort()
c = 0
for k in range(n):
    for items in lst:
        lst.remove(items)
        if items in lst:
            lst[lst.index(items)] = lst[lst.index(items)] - 1
        lst.append(items)
for items in lst:
    if items > 0:
        c = c + items
print(c)

