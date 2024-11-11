def factors(n):
    i=2
    blanck=[]
    while i**2<=n :
        if n%i==0:
            blanck.append(i)
            n//=i
        else:
            i+=1
    if n>1:
        blanck.append(n)
        n=1
    return blanck

def cold(n):
    if n==1:
        print(1)
        return 0
    x=factors(n)
    if len(x)==2:
        return 2
    if len(x)==1:
        print(1)
        return 0
    temp=[]
    s=1
    for i in range(len(x)-1):
        s*=x[i]
    temp.append(s)
    temp.append(x[-1])
    print(1)
    return x[0]*x[1]


print(cold(int(input())))