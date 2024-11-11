n = int(input())
a = list(map(int, (input().split())))
a.append(0)
mon = 1000
kab = 0
x = 0
for i in range(n):
    if a[i] <= a[i+1]:
        kab = mon//a[i]
        mon += kab*(a[i+1]-a[i])
print(mon)