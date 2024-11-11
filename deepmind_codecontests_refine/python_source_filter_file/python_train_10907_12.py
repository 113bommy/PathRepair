x,k,d = map(int, input().split())
x1=abs(x)
 
if x>=k*d:
    print(x-k*d)
else:
    if (k-x//d)%2 == 0:
        print(x%d)
    else:
        print(d-x%d)