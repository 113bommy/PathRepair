n = int(input())
d = sorted(list(map(int, input().split())))
s = 1
c = 0
for i in d:
    if i >= s:
        c += 1
        s += 1
print(s)
