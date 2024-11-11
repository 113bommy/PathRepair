for i in range(int(input())):
    num=int(input())
    count2=0
    count3=0
    while int(num)%2==0:
        num=num/2
        count2+=1
    while int(num)%3==0:
        num=num/3
        count3+=1
    if int(num)==1 and count3>=count3:
        print(int(2*count3-count2))
    else:
        print(0)