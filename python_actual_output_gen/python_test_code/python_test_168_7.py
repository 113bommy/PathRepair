n = int(input())
a = list(map(int,input().split()))
bool = True
for i in range(n):
    x = 0
    for j in range(n):
        if (a[i] == a[j]):
            x += 1
    if (n < 2*(x-1) ):
        bool = False
        break
if (bool):
    print("YES")
else:
    print("NO")