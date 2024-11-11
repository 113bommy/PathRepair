l, r, x, y, k = list(map(int, input().split()))
if (x * k <= r and y * k >= l and (l / k != r / k or l / k * k == l)):
    print("YES")
else:
    print("NO")