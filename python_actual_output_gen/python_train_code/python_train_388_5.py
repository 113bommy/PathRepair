n=int(input())
l=list(map(int,input().split()))
p1=0
p2=0
ma=0
mi=10000000
for i in range(n) :
    if mi>l[i] :
        mi=l[i]
        p1=i
    if ma<l[i] :
        ma=l[i]
        p2=i
if p1>p2 :
    if n-p2-1>p1 :
        print(n-p2-1)
    else :
        print(p1)
else :
    if n-p1-1>p1 :
        print(n-p1-1)
    else :
        print(p2)
    
    
