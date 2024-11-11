import math
def fact(x):
    result=1
    for i in range(x,1,-1):
        result*=i
    return result

def comb(n,r):
    return fact(n)/(fact(n-r)*fact(r))

n=int(input().strip())
d={}
for i in range(n):
    a=input().strip()
    d[a[0]]=d.get(a[0],[])+[a]
result=0
for i in d:
    if(len(d[i])>2):
        n=len(d[i])
        if(n==3):
            result+=1
        else:
            if(n%2==0):
                result+=((comb(n//2,2))*2)
            else:
                result+=(comb(n//2,2))+comb(math.ceil(n/2),2)
print(result)
