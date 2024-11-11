n, m = map(int, input().split())
a = input()
b = input()
listans = []
for i in range(n):
    listans.append(i)
for i in range(len(b) - len(a) + 1):
    templist = []
    for j in range(len(a)):
        if a[j] != b[i + j]:
            templist.append(i + j + 1)
    if len(templist) < len(listans):
        listasn = templist
print(len(listans))
for i in listans:
    print(i, end=" ")
