a, x, y = [list(map(int, input().split()))for i in range(3)]
if max(a[2], sorted(x)[-1])<min(a[3],sorted(y)[0]): print("No war")
else: print("War")