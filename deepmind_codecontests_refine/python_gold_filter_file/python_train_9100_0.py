n, x = (int(x) for x in input().split())
res = abs(sum([int(x) for x in input().split()]))
if res % x == 0:
    print(int(res/x))
else:
    print(int(res/x + 1))