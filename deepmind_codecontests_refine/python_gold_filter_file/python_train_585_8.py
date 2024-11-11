import math
k,d,t=map(int,input().split())
if(d==k):
    print(t)
elif(k<d):
    D=(2*t)//(d+k)
    r=(2*t)%(d+k)
    if(r<=2*k):
        print(D*d+r/2)
    else:
        print(D*d+k+r-2*k)
        
else:
    a=math.ceil(k/d)
    D=(2*t)//(a*d+k)
    r=(2*t)%(a*d+k)
    if(r<=2*k):
        print(D*a*d+r/2)
    else:
        print(D*a*d+k+r-2*k)




    