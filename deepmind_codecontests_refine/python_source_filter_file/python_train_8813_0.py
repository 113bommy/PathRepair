m=1000000007
def power(x, y, p=1000000007):
    res = 1
    x = x % p 
    while (y > 0) :
        if ((y & 1) == 1) :
            res = (res * x) % p
        y = y >> 1     
        x = (x * x) % p         
    return res
x,k=list(map(int,input().split()))
if(x==0):
    print(0)
elif(k==0):
    print(x*2)
else:
    temp=power(2,k)
    maxi=(((x*temp)%m)*2)%m
    mini=(m+maxi-(2*(temp-1))%m)%m
    print((((maxi+mini)%m)*500000004)%m)