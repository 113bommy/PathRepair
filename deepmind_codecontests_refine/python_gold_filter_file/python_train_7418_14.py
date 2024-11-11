test=int(input())
for _ in range(test):
    n=int(input())
    if n<=30:
        print("NO")
    else:
        x=n-30
        if n-30==6:
            print("YES")
            print("6 10 15 %d" %(x-1))
        elif n-30==10:
            print("YES")
            print("6 15 14 %d" %(x-5))
        elif n-30==14:
            print("YES")
            print("6 10 15 %d" %(x-1))
        else:
            print("YES")
            print("6 10 14 %d" %(x))