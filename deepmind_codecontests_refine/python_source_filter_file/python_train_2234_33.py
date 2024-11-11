

n,m = map(int,input().split())
l1=[]
k=n//2
i=0
if(n<m):
    a=-1


    
else:
    if(n%2==0):
        a=n/2
    else:
        a=int(n/2)+1
    while(a%m!=0):
        a+=1

print(a)

