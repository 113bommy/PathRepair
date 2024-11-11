t=int(input(""))

for i in range(t):
    a,b=map(int,input("").split())
    sub=abs(a-b)
    if sub>10:
        s=sub//10
        if sub%10!=0:
            total=s+1
            print(total)
        else:
            print(s)
    elif sub==0:
        print("0")
    elif sub<10:
        print("1")


    






    
