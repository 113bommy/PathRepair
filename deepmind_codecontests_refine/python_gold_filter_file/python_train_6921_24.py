n = int(input())
l = list(map(int, input().split()))
l.sort()
t = 1
s = l[0]
i = 1
while i < len(l):
    if l[i] >= s:
        t += 1
        s += l[i]
    else:
        del l[i]
        i -= 1
    i += 1
print(t)
