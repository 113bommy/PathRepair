n, c = map(int, input().split())
w = list(map(int, input().split()))
nw = 0
for x in range(n-1):
    if w[x+1] - w[x] > c:
        nw = 1
    else:
        nw += 1

print(nw)