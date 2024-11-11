def BubbleSort(a, n):
    for i in range(n):
        for j in range(n-1, i, -1):
            if int(a[j][1]) < int(a[j - 1][1]):
                a[j], a[j-1] = a[j-1], a[j]
    return a


def SelectionSort(a, n):
    for i in range(n):
        mini = i
        for j in range(i, n):
            if int(a[j][1]) < int(a[mini][1]):
                mini = j
        a[i], a[mini] = a[mini], a[i]
    return a


n = int(input())
a = input().split()


b = a
a = BubbleSort(a, n)
b = SelectionSort(b, n)


print(*a)
print("Stable")
print(*b)

if a == b:
    print("Stable")
else:
    print("Not Stable")