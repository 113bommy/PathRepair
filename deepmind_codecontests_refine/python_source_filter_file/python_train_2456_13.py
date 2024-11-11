n, k = map(int, input().split())
a = [int(i) for i in input().split()]
b = a[0] % k
f = 0
p = a[0]
s = 0
for i in range(n):
    if a[i] % k != b:
        s = -1
        break
    
    if a[i] < p:
        s += (p - a[i]) // k
        p = a[i]
    if a[i] > p:
        s += (a[i] - p) // k
print(s)