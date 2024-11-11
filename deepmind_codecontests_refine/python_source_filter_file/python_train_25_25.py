t=int(input())
for i in range(t):
    n=int(input())
    l=[]
    for j in range(n):
        l.append(list(input()))
    a,b,c,d=l[0][1],l[1][0],l[n-2][n-1],l[n-1][n-2]
    if (a=="1"):
        if(b=="1"):
            if (c=="1"):
                if(d=="1"):
                    print(2)
                    print("1 2")
                    print("2 1")
                else:
                    print("1")
                    print(str(n-1)+ " "+str(n))
            else:
                if(d=="1"):
                    print("1")
                    print(str(n)+ " "+str(n-1))
                else:
                    print(0)
        else:
            if (c=="1"):
                if(d=="1"):
                    print("1")
                    print("1 2")
                else:
                    print(2)
                    print(str(n-1)+ " "+str(n))
                    print("2 1")
            else:
                if(d=="1"):
                    print(2)
                    print(str(n-1)+ " "+str(n))
                    print("1 2")
                else:
                    print("1")
                    print("1 2")
    else:
        if(b=="1"):
            if (c=="1"):
                if(d=="1"):
                    print("1")
                    # print("1 2")
                    print("2 1")
                else:
                    print(2)
                    print(str(n-1)+ " "+str(n))
                    print("1 2")
            else:
                if(d=="1"):
                    print(2)
                    print(str(n)+ " "+str(n-1))
                    print("1 2")
                else:
                    print("1")
                    print("1 2")
        else:
            if (c=="1"):
                if(d=="1"):
                    print(0)
                else:
                    print("1")
                    print(str(n)+ " "+str(n-1))
            else:
                if(d=="1"):
                    print("1")
                    print(str(n-1)+ " "+str(n))
                else:
                    print(2)
                    print(str(n-1)+ " "+str(n))
                    print(str(n)+ " "+str(n-1))