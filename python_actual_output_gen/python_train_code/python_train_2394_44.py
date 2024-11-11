n = int(input())
a = input().strip().split()
for index,item in enumerate(a):
    a[index] = int(item)
a.sort()
s = a[0]
m = 1
for i in range(1,n):
    if a[i] > s:
        s += a[i]
        m += 1
print(m)
