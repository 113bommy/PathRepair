w, h, x, y, r = map(int, input().split())
if(min([x, y, w - x, w - y]) >= r):
    print("Yes")
else:
    print("No")