n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
p, q = 0, 0
for i in range(n):
    if a[i] > b[i]:
        p += (a[i] - b[i]) * 2
    elif a[i] < b[i]:
        q += (b[i] - a[i]) // 2

if p == q:
    print("Yes")
else:
    print("No")