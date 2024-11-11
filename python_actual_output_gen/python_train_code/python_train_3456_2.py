x=list(map(int,input().split()))
c=min(x[1],x[0])
v="Second"
if c>x[2]*2:
    v="First"
print(v)