n = int(input())
used = []
ekv = []
a = []
for i in range(n):
    s = list(input())
    a.append(s)
a.sort()

j = 1
t = 0
a.append("dsh")
r = 0
for i in range(n-1):
    r = 0
    for k in range(len(a[i])):
        if a[i][k] in a[i+1]:
            r = 1
            break
    if r == 0:
        j += 1

print(j)
