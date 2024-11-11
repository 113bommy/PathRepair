n = int(input())
a = list(map(int, input().split()))

fp = 0
flag = 0
for i in range(n):
    if i==a[i]:
        fp += 1
    elif flag == 0 and i == a[a[i]]:
        a[a[i]], a[i] = a[i], a[a[i]]
        fp += 1
        flag = 1
if flag == 0:
    fp += 1

print(fp)
