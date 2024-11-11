n,k=map(int,input().split())
a=len(bin(n).replace('0b',''))
b=int('1'*a,2)
if(n<b):
    b=int('1'*(a-1),2)
if k==1:
    print(b)
else:
    if(b==n):
        print(b)
    else:   
        print(b^(b+1))
