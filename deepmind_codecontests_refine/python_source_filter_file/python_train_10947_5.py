a=int(input())
r=0
z=list()
while r<a:
    b=int(input())
    x=0
    while (b%2)==0 or (b%3)==0 or (b%5)==0:
        if (b%2)==0:
            b=b/2
        elif (b%3)==0:
            b=b/3*2
        elif (b%5)==0:
            b=b/5*2
        x=x+1
    if b==1:
        z.append(x)
    else:
        z.append(-1)
    r=r+1
r=0
while r<a:
    print(z[r])
    r=r+1
