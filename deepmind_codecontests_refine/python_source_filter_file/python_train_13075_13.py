n, m = map(int, input().split())
a = input()
b = input()
listans = []
for i in range(n):
    listans.append(i+1)
for i in range(len(b) - len(a) + 1):
    templist = []
    for j in range(len(a)):
        if a[j] != b[i + j]:
            templist.append(i +1)
    if len(templist) < len(listans):
        listans = templist
print(len(listans))
for i in listans:
    print(i, end=" ")
