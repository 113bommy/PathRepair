n,k=map(int,input().split(' '))
if n%2==0:
    if k==1:
        print("Yes")
    else:
        print("No")
else:
    if n%4==1:
        if n%2==n%3 or n%3==0:
            if k<=2:
                print("Yes")
            else:
                print("No")
        else:
            if k<=3:
                print("Yes")
            else:
                print("No")
    else:
        if n%6==1 or n%6==3:
            if k<=2:
                print("Yes")
            else:
                print("No")
        else:
            if n%5!=4:
                if k<=3:
                    print("Yes")
                else:
                    print("No")
            else:
                for i in range(1,k+1):
                    if n%i!=i-1:
                        i-=1
                        break
                if i<=k:
                    print("Yes")
                else:
                    print("No")
            