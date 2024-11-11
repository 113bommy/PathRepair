N = int(input())
maxv = -2000000
minv = int(input())
for i in range(N-1):
    _ = int(input())
    maxv = max(maxv,_-minv)
    minv = min(minv,_)
print(maxv)
