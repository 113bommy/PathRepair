n, k = map(int, input().split())
p = list(map(int, input().split()))
a = sum(p[0:k])
l = []
for i in range(n-k+1):
    a = a+p[i]-p[i+k-1]
    l.append(a)
print((max(l)+k)/2)