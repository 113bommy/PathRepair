h, w = map(int, input().split())
if h == 1 or w == 1:
    print(a)
else:
    print(int(((h*w)+1) / 2))