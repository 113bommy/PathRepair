t = int(input())
for _ in range(t):
    n = int(input())
    h = list(map(int, input().split()))
    maxv = minv = 0
    for i in range(len(h)-1):
        maxv = max(maxv, h[i+1]-h[i])
        minv = max(minv, h[i]-h[i+1])
    print(maxv, minv)