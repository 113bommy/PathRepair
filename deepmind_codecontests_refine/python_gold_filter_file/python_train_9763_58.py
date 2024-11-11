a,b,c,k=map(int, input().split())
if a+b-k>=0:
    print(min(a,k))
else:
    print(2*a-k+b)