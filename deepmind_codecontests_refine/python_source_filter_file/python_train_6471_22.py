k=int(input())
if (k<=9):
    print(k)
elif(k<=189):#no. less than 100
    if ((k-9)%2==0):
        r=(k-9)/2
        x=str(r+9)
        print(x[1:2])
    else:
        r=(k-9)//2
        x=str(r+10)
        print(x[0:1])
elif(k>=2889):#less than 1000
    r=(k-189)%3
    if r==0:
        x=str((k-189)/3+99)
        print(x[2:3])
    elif(r==1):
        x =str((k-189)//3+100)
        print(x[0:1])
    else:
        x=str((k-189)//3+100)
        print(x[1:2])
else:
    r=(k-2889)%4
    if r==0:
        x=str((k-2889)/4+999)
        print(x[3:4])
    else:
        x=str((k-2889)//4+1000)
        if r==1:
            print(x[0:1])
        elif(r==2):
            print(x[1:2])
        else:
            print(x[2:3])

