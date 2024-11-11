n, m = map(int, input().split())

sm = 0

left = sum(x for x in range(n))
center = sum(abs(x - n//2) for x in range(1, n+1))

for _ in range(m):
    x, d = map(int, input().split())
    
    sm += x * n
    
    if d > 0:
        sm += d * left
    else:
        sm += d * center

print(sm / n)