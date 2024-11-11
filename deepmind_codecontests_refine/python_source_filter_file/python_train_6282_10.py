from math import gcd
n,m=list(map(int,input().split()))
a=list(map(int,input().rstrip().split()))
b=list(map(int,input().rstrip().split()))
maina=0
if n==m:
    j=0
    if a[0]<0:
        j+=1
    if b[0]<0:
        j+=1
    h=gcd(abs(a[0]),abs(b[0]))
    if h==1:
        print('-'+str(abs(a[0]//h))+'/'+str(abs(b[0]//h)))
    else:
        print(str(abs(a[0]//h)) + '/' + str(abs(b[0]//h)))
elif n<m:
    print('0'+'/'+'1')
else:
    h=0
    if a[0]<=0:
        h+=1
    if b[0]<=0:
        h+=1
    if h==1:
        print('-Infinity')
    else:
        print('Infinity')
        
        
        
        
    