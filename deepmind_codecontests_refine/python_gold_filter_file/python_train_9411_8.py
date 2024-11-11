a=input().split(' ')
first=int(a[0])
second=int(a[1])
third=int(a[2])
sum=(first+second+third)
if sum%2==1:
    print("Impossible")
else:
    x=first
    y=second
    z=third
    if x-int(x)!=0 or y-int(y)!=0 or z-int(z)!=0:
        print("Impossible")

    else:
        x=int(sum/2-third)
        y=int(sum/2-first)
        z=int(sum/2-second)
        if x<0 or y<0 or z<0 or x==0 and y==0 and z==0:
            print("Impossible")
        else:
            print(x, y, z)
    
