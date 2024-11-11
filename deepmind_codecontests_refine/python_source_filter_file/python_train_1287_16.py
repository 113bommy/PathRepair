n=int(input())
l=list(map(int,input().split()))
s=sum(l)
if s%2==0 :
    print(n)
else :
    print(max(1,n-1))
    
    
