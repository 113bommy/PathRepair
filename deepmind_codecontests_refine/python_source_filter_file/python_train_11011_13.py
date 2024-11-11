n,k = map(int,input().split())
a = list(map(int,input().split()))

ML = 20
r = min(ML,k)

for l in range(r):
    imos = [0]*(n+1)
    for i in range(n):
        left = max(0,i-a[i])
        right = min(n,i+a[i]+1)
        
        imos[left] += 1
        imos[right] -= 1
        
    c = 0
    for i in range(n):
        c += imos[i]
        a[i] = c
        
print(*a)