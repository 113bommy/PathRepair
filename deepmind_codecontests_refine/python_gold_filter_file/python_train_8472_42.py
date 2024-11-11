n,k = [int(x) for x in input().split()]
if k <= int((n + 1) / 2):
    print(int(2 * k - 1))
else:
    print(int((k - int((n + 1) / 2)) * 2))
