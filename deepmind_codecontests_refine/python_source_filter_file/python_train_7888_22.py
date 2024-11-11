N = int(input())
XL = [tuple(map(int, input().split())) for i in range(N)]
XL.sort(key=lambda x: x[0])

right = -10**9
removed = 0
for x, l in XL:
    if x-l < right:
        removed += 1
    else:
        right = x+l
print(N-removed)
