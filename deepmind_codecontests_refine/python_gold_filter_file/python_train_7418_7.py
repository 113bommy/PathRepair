t=int(input())
for i in range(t):
    n=int(input())
    x=(n-(6+10+14))
    if x<=0:
        print("no")
    else:
        if x!=6 and x!=10 and x!=14:
            print("yes")
            print(x,6,10,14)
        elif x==6 and x!=10 and x!=14:
            print("yes")
            print(5,6,10,15)
        elif x!=6 and x==10 and x!=14:
            print("yes")
            print(5,6,14,15)
        elif x!=6 and x!=10 and x==14: 
            print("yes")
            print(6,10,15,13)