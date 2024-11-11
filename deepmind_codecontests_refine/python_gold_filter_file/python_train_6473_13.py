n = int( input() )
a = list( map( int, input().split() ) )
a.sort()
res = 1000000000
for s in range(n):
    oneloop = 0
    for i in range(n):
      oneloop += abs(a[i] - a[s]) % 2
    res = min(oneloop, res)
print(res)
