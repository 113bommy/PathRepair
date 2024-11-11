l, r = map(int, input().split())
if r - l > 1:
    print("YES")
    for i in range(l, r, 2):
        print(i, i + 1)
else:
    print("NO")
