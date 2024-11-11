a, b, n = map(int,input().split())
a=str(a)
t=a
k=''
t1=n
for x in range(10):
        a = str(a)
        x=str(x)
        a=a+x
        a=int(a)
        #print(a)
        #print(x)
        if(a%b==0):
            break
        else:
            a=str(a)
            a=a[:-1]

if(t==a):
    o=-1
    print(o)
else:
    a=str(a)
    z=n-len(a)+1
    print(int(str(a)+z*'0'))

