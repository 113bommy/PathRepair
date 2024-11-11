t = int(input())
for i in range(t):
    a,b = list(map(int, input().split()))
    if a/b == 2:
        print("YES")
    else:
        print("NO")
