n, h = map(int, input().split())
c = 0
a = set(map(int, input().split()))
for i in a:
    if(int(i) > h):
        c += 2
    else:
        c += 1
print(c)
