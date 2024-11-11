n=int(input())
l=list(map(int,input().split()))
ma=0
p1=0
p2=0
for i in range(n-1) :
    if (i+1)%2!=0 :
        p1=p1+abs(l[i]-l[i-1])
        p2=p2-abs(l[i]-l[i-1])
        if p2<0 :
            p2=0
        ma=max(p1,ma)
    else :
        p2=p2+abs(l[i]-l[i-1])
        p1=p1-abs(l[i]-l[i-1])
        if p1<0 :
            p1=0
        ma=max(p2,ma)
print(ma)
        
