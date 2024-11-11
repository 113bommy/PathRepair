n , x = map( int , input().split() )
minutes = 1
for i in range(n):
    l , r = map(int , input().split())
    diff = l - minutes
    minutes = minutes + diff%x
    minutes = minutes + (r-l)
print(minutes)