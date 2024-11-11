x1, y1, x2, y2 = list(map(int, input().split()))
sa = abs(x1-x2); sb = abs(y1-y2);
if sa == sb:
    print(*(y1, x2, y2, x1))
elif x1 == x2:
    print(*(x1 + sa, y1, x2 + sa, y2))
elif y1 == y2:
    print(*(x1, y1 + sb, x2, y2 + sb))
else:
    print(-1)