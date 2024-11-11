n , m = map(int,input().split())
c = min(n//2 , m//24)
n-=(2*c)
m-=(24*c)
c = min(n//3 , m//14)
n-=(3*c)
m-=(14*c)
c = min(n//4,  m//4)
n-=(4*c)
m-=(4*c)
c = min(n , m//32)
n-=(c)
m-=(32*c)
c=m//44
m-=(44*c)
if m>=2 and 10*n +m >=22:
    print("Ciel")
else:
    print("Hanako")

    
    