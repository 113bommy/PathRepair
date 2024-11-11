n,k=map(int,input().split(' '))
C=list(map(int,input().split(' ')))
hd=C[0]
C.pop(0)
i=k
count=1
while(i<=n):
    if(len(C)>0 and C[0]>i and C[0]<=i+k):
        i=C[0]
        C.pop(0)
        count+=1
    else:
        i+=k
        if(i<=n):
            count+=1
print(count)
        
        
    
