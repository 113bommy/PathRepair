def orig_copies(x, y):
    x1, y1 = y, y - 1
    if y1 == 0 and x1 > 0:
        return "No"
    elif y1 > 0 and (x - y1) % 2 == 1:
        return "No"
    elif y == 0:
        return "No"
    elif x - y1 < 0:
        return "No"
    return "Yes"


X, Y = [int(i) for i in input().split()]
print(orig_copies(X, Y))
