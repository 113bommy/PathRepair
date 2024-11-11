a, b = map( int, input().split() )
k=0
while a<b:
    a=3*a
    b=2*b
    k=k+1
print(k)