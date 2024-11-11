n, t = list(map(int, input().split()))
a = list(map(int, input().split()))
flag = 0
for i in range (len(a)):
    a[i] = 86400 - a[i]

for i in range (len(a)):
    t -= a[i]
    if t == 0:
        print (i + 1)
        break