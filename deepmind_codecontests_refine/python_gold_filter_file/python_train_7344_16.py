n, b, d = map(int, input().split())
l = list(map(int, input().split()))
l = list(filter(lambda x: x <= b, l))
s = 0
c = 0
for i in range(0, len(l)):
    s = s+l[i]
    if s > d:
        s = 0
        c = c+1
print(c)
