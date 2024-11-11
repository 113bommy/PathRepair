def f():
    l, r = map(int, input().split())
    return 2 * l > r


t = int(input())
for i in range(t):
    if f():
        print("YES")
    else:
        print("NO")