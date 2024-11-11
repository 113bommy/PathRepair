a,b,n=map(int,input().split())
a1,b1,n1=a,b,n

while n1>=0:             
   
    while n>0:
        a,n=n,a%n
    if n1-a<0:
        print('0')
#        break
    n1=n1-a
    n=n1
    a=a1

    while n>0:
        b,n=n,b%n
    if n1-b<0:
        print('1')
#        break
    n1=n1-b
    n=n1
    b=b1
