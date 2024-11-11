for i in range(int(input())):
    n = int(input())
    a1 =0
    a2 =0
    a3 =0
    if(n%3 ==0):
        a1 = n//3
    elif n%5==0:a2 =n//5
    elif n%7 ==0:a3 =n//7
    else:
        a4 = n%3
        if a4 ==2:
            a1 = (n-5)//3
            a2 =1
        else:
            a1 = (n-7)//3
            a3 =1
    if n==4:
        print(-1)
    else:
        print(a1,a2,a3)