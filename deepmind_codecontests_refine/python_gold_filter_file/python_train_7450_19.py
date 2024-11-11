n,k=map(int,input().split())
if k%2!=0:
    print(1)
else:
    c=0
    while k%2==0:
        k=k//2
        c+=1
    print(c+1)        
