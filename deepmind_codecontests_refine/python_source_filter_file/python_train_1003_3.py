n = int(input())
a = list(map(int, input().split()))
t = True
for i in range(len(a) - 1):
    if a[i + 1] - a[i] >= 2:
        print("NO")
        t = False
        break
if (t):
    print("YES")