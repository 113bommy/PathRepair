n = int(input())
a = [int(i) for i in input().split()]
a.sort()
for i in range(0, (len(a) - 1), 2) :
    a[i], a[i + 1] = a[i + 1], a[i]
c = 0
for i in range(1, (len(a) - 1)) :
    if((a[i] < a[i - 1]) and (a[i] < a[i + 1])) :
        c += 1
print(c)
print(*a)