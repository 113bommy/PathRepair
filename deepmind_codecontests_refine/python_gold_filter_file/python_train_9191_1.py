t = int(input())
for i in range(t):
    n = int(input())
    if n & -n == n:
        print("NO")
    else:
        print("YES")
