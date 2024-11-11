def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors


n,k=map(int,input().split())
a=list(map(int,input().split()))

x=sum(a)

lst=make_divisors(x)

lst.reverse()

for can in lst:
    aa=list(map(lambda x:x%can,a))
    aa.sort()

    cnt=0
    l=0
    r=0
    lll=0
    rrr=len(aa)-1
    while lll<=rrr:
        if l<r:
            l+=aa[lll]
            lll+=1
        
        else:
            r+=can-aa[rrr]
            rrr-=1
    
    if (l+r)//2<=k:
        print(can)
        exit()