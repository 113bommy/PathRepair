n,a,b = map(int, input().split())
x = [int(x) for x in input().split(' ')]

mp = 0
for i in range(n-1):
    mp += min(a*(x[i+1]-x[i], b))
    
print(mp)