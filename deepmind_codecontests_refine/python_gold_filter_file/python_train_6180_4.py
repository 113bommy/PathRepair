a = input().split()
t = 0
a.sort()
for i in range(3):
    if a[i] == a[i+1]:
        t += 1
print(t)