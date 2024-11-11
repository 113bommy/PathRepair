n=(int(input()))
if(n<=2):
    print("-1")
else:
    if(n%2==1):
            x=(pow(n,2)-1)/2;
            y=(pow(n,2)+1)/2;
            a=(int)(x)
            b=(int)(y)
            print(a," ",b)
    else:
        x=(int)(pow(n/2,2)-1);
        y=(int)(pow(n/2,2)+1);
        a=(int)(x)
        b=(int)(y)
        print(a," ",b)