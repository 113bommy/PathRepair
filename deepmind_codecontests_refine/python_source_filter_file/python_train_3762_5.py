d = int(input())
l = list(sorted(map(int, input().split())))
print(l)
s = 0
if(len(l) % 2 != 0):
    for i in range(int(d / 2)):
        s += (l[i] + l[-i]) ** 2
    s += l[int(len(l) / 2) + 1] ** 2
else:
    for i in range(int(d / 2)):
        s += (l[i] + l[-i - 1]) ** 2

print(s)
