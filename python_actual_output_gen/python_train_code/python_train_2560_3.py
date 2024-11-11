t=int(input())
def tallest(x):
    if x<2:return 0
    s=2
    base,ind2=2,0
    flagger=s
    while s<x:
        base+=2
        ind2+=1
        flagger=s
        s=(s+base)+ind2
    if s==x:
        return s
    return flagger


for _ in range(t):
    n=int(input())
    ans=0
    while n>=2:
        z=tallest(n)
        print("For n:",n,"Tallest is:",z)
        n-=z
        if z>1:
            ans+=1
    print(ans)

