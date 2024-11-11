n = int(input())
yi = list(map(int, input().split()))

steps = yi[1] - yi[0], (yi[2] - yi[0])/2, yi[1] - yi[2]
if any(len(set(l)) == 2 for l in ([y - i * step for i, y in enumerate(yi)] for step in steps)):
    print('Yes')
else:
    print('No')

