for _ in range(int(input())):
    n=int(input())
    m,flag=0,False
    while n!=1:
        if n%2==0:
            n//=2
            m+=1
        elif n%3==0:
            n=(n*2)/3
            m+=1
        elif n%5==0:
            n=(n*4)/5
            m+=1
        else:
            flag=True
            break
    print("-1" if flag else m)