__author__ = 'myduomilia'

n = int(input())
arr = []
for i in range(3, 361):
    arr.append((i - 2) * 180 / i)
for i in range(n):
    val = int(input())
    if val in arr:
        print("YES")
    else:
        print("NO")

