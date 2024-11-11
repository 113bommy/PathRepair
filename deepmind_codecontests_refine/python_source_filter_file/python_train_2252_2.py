n=int(input())
l=[int(i) for i in input().split()]
sq=[]
no=[]
for i in l: 
    if int(i**0.5)==i**0.5:
        sq.append(i)
    else:
        no.append(i)
if len(sq)==n//2:
    print(0)
    exit()
if len(sq)>n//2:
    ab=[]
    rem=len(sq)-n//2 
    for i in sq: 
        if i==0 or i==1:
            ab.append(2)
        else:
            ab.append(1)
    ab.sort()
    print(sum(ab[:rem]))
else: 
    from math import floor as f,ceil as c 
    ab=[]
    rem=n//2-len(sq)
    for i in no: 
        lo=f(i**0.5)
        lo*=lo 
        up=c(i**0.5)
        up*=up 
        ab.append(min(i-lo,up-i))
    ab.sort()
    print(sum(ab[:rem]))
        