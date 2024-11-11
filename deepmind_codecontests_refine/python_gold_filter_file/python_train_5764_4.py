n,m  = map(int,input().split())
r = pow(3,n,m)
if r == 0 :
    r += m
print(r-1)
