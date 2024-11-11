n = int(input())
m = int(input())
L = [int(input()) for _ in range(n)]
r = 1
L.sort()
while m >= 0:
    m = m - L[n-r]
    r+=1
print(r-2)
