n, w = map(int, input().split())
a = list(map(int, input().split()))

r = 0
s = 0
smax = a[0]
smin = a[0]
for i in a:
    s += i
    smin = min(s, smin)
    smax = max(s, smax)
r = w - max(0, smax) + min(0, smin) + 1

## max = -1   min = -11
r = max(r, 0)

print(r)
    
        
