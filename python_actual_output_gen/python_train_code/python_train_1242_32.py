n, m = [int(i) for i in input().split()]
if abs(m - 1) > abs(n - m):
    print(m - 1)
elif abs(m - 1) == abs(n - m):
    if m > 1:
        print(m - 1)
    else:
        print(m + 1)
else:
    print(m + 1)