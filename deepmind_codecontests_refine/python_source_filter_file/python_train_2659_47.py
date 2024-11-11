n, h = map(int, input().split())
a = list(map(int, input().split()))
s = 0
for i in a:
    if i < h:
        s += 1
    else:
        s += 2
print(s)
