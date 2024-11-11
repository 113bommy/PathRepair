n = int( input() )
a = list( map( int, input().split() ) )

MAXN = (10**6+5)

p = [True]*(MAXN+1)

memo = {}

for i in range(2,MAXN):
    if p[i]:
        memo[i*i] = 1
        for j in range(2,MAXN,i):
            p[j] = False

for i in a:
    if i in memo:
        print( "YES" )
    else:
        print( "NO" )
