a,b=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
if len(l1)>len(l2):
    x='Infinity'
    if (l1[0]>0 and l2[0]>0) or (l1[0]<0 and l2[0]<0) :
        print('Infinity')
    else:
        print('-Infinity')
elif len(l1)<len(l2):
    print('0/1',sep='')
else:
    n=l1[0];m=l2[0]
    for i in range(2,abs(min(n,m))//2+2):
        if n%i==0 and m%i==0:
            n=n//i;m=m//i
    if (n>0 and m>0) or (n<0 and m<0):
        print(abs(n),'/',abs(m),sep='')
    else:
        print('-',abs(n),'/',abs(m),sep='')
