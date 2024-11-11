a = input()
a = a.split(' ')
n = int(a[0])
k = int(a[1])
d = []
a = input().split(' ')
for i in range(n):
    if k%int(a[i]) == 0:
        d.append(int(a[i]))
d.sort()
print(k//int(d[-1]))
