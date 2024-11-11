n = int(input())

maxv = 10**18
minv = 10**18

for i in range(n):
    r= int(input())
    maxv = max(maxv, r - minv)
    minv = min(minv, r)

print(maxv)

