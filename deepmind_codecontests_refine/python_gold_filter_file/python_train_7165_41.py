n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x = 0
for i in range(n):
    if a[i] < b[i]:
        x += (b[i] - a[i])//2
    else:
        x -= (a[i] - b[i])
if x < 0:
    print("No")
else:
    print("Yes")
