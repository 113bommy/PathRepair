n=int(input())
a=list(map(int,input().split()))
harf=sum(a)/2
l,r,i=0,a[0],0
while r<harf:
    i+=1
    l=r
    r+=a[i]
print(int(min(harf-l,r-harf)*2))