t = int(input())
for i in range(t):
    l , r = map(int , input().split())
    if 2*l < r + 2:
        print("NO")
    else:
        print("YES")