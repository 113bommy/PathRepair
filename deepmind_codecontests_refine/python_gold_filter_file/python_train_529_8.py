a,b,c=map(int,input().split())
i=0
x=0
z=0
while i<a:
    p,q=map(int,input().split())
    z+=(p-x)//c
    x=p+q
    i+=1
z+=(b-x)//c
print (z)