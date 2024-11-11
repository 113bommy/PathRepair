n, h = map(int, input().split())
friends = [int(i) for i in input().split()]
wid = len(friends)
for i in friends:
    if i >= h:
        wid += 1
print(wid)