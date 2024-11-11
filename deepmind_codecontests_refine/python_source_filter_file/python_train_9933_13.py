x = [int(s) for s in input().split()]
h = [int(s) for s in input().split()]
n, k, j = x[0], x[1], 0


s = 0
for i in range(k):
    s += h[i]
s1 = s
if n > k:
    for i in range(1, n-k):
        s1 = s1 - h[i-1] + h[i+k-1]
        if s > s1:
            s, j = s1, i
    print(j+1)
else:
    print(1)