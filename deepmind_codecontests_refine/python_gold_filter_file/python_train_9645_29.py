input()
a = list(map(int, input().split()))
a.sort()
p = -1
s = 0
for i in range(0, len(a)):
    if a[i] != 0 and a[i] != p:
        s = s + 1
        p = a[i]
print(s)
