n = int(input())
a = list(map(int, input().split()))
arr1 = []
arr2 = []
arr3 = []

for i in range(n):
    if a[i] < 0:
        arr1.append(a[i])
    if a[i] == 0:
        arr3.append(a[i])
    if a[i] > 0:
        arr2.append(a[i])

if len(arr2) == 0:
    for i in range(2):
        arr2.append(arr1.pop())

if len(arr1) % 2 == 0:
    arr3.append(arr1.pop(-1))
    #arr1.pop()

print("%d" % len(arr1), end=' ')
for i in range(len(arr1)):
    print(arr1[i],end=' ')

print("\n%d" % len(arr2), end=' ')
for i in range(len(arr2)):
    print(arr2[i], end=' ')

print("\n%d" % len(arr3), end=' ')
for i in range(len(arr3)):
    print(arr3[i],end=' ')