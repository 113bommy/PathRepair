n, k = map( int, input().split() )
a = list( map( int, input().split() ) )
c = i = 0
print(a)
for _ in range(n-1):
    if a[i] + a[i+1] < k:
        c += k-(a[i]+a[i+1])
        a[i+1] += k-(a[i]+a[i+1])
    i += 1
    
print(c)
print(( ' '.join( [str(x) for x in a] ) ))