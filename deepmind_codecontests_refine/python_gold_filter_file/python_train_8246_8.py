#import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n=int(input())
s=list(input().strip())
se=list(set(s))
c=0
se.sort(reverse=True)
m=n
for j in range(len(se)):
    n=m-c
    k=1
    while k<n:
        if s[k]==se[j] :
            if ord(s[k-1])+1==ord(s[k]):
                del s[k]
                c=c+1
                n=n-1
            else:
                k=k+1
        else:
            k=k+1
    n=m-c
    for k in range(n-2,-1,-1):
        if s[k]==se[j] :
            if ord(s[k+1])+1==ord(s[k]):
                del s[k]
                c=c+1
print(c)
    
        
    

        
    