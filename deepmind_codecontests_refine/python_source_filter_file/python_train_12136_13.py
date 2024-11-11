'''n=input().split()
d=int(input())
c={1:int(n[0]),2:int(n[1])}
c[3]=c[2]-c[1]
c[4]=c[3]-c[2]
f=(d)%6
if f==2:
    print(c[2]%1000000007)
if f==3:
    print(c[3]%1000000007)
if f==4:
    print(c[4]%1000000007)
if f==5:
    print((-1*c[2])%1000000007)
if f==0:
    print((-1*c[3])%1000000007)
if f==1:
    print((-1*c[4])%1000000007)'''
n=int(input())
y=input()
f={}
d=''
if n==2:
    print(y)
elif n%2==1:
    for i in range(n-2,0,-2):
        d+=y[i]
    for i in range(0,n,2):
        d+=y[i]
else:
    for i in range(n-1,0,-2):
        d+=y[i]
    for i in range(1,n,2):
        d+=y[i]
print(d)

    
    


