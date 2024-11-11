for i in range(int(input())):
    n = int(input())
    if n%3==0:
        print("YES")
    elif n%7==0:
        print("YES")
    else:
        k=0
        while n-7>0:
            n = n-7
            if n%3==0:
                k=1
                break
        if k==1:
            print("YES")
        else:
            print("NO")