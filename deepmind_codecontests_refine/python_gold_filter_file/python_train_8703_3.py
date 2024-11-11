l, r, x, y, k = list(map(int, input().split()))


def possible():
    global l, r, x, y, k
    for i in range(x, y+1):
        if l <= i*k <= r:
            return True
        if i * k > r:
            break
    return False

if possible():
    print("YES")
else:
    print("NO")