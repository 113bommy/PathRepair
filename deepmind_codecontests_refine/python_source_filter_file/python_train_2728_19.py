import sys
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    for i in range(1, n):
        if abs(a[i]-a[i-1])>1:
            print("YES")
            print(i-1, i)
            break
    else:
        print("NO")
