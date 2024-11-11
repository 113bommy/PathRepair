n = int(input())
h = list(map(int, input().split()))
idx, size = 0, 0
for j in range(1,len(h)-1):
    if h[j] < h[j+1]:
        idx = j
    size = max(size,j-idx)
print(size)