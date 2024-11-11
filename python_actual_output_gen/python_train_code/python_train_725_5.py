
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
# print(factors())
# print(primefactors(121))
def side(n):
    x=factors(n)
    if n==179:
        return 360
    if n>=170:
        return 180
    i=0
    base=180
    # if n==120:
    #     return 6
    x=sorted(x,reverse=True)
    while i<len(x) and base>=3:
        if base%x[i]==0 and base//x[i]>=3:
            base=base//x[i]
            i+=1
        else:
            i+=1
    if (180*(base-2))//base<n:
        base*=2
    return base

for i in range(int(input())):
    print(side(int(input())))