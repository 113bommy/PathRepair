l=list(map(int,input().split()))
s=sum(l)
if sum==0:
    print(-1)
elif s%5!=0:
    print(-1)
else:
    print(s//5)
    
