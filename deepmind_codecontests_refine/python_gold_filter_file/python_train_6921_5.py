n = int(input())
l = list(map(int, input().split()))

l.sort()

t = 0
r = 0
for i in range(len(l)):
    if t <= l[i]:
        r += 1
        t += l[i]

print(r)