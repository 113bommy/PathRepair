for _ in range(0,int(input())):
    s=int(input())
    b=list(str(s))
    a=[int(i) for i in b]
    if len(a)==1:
        if a[0]==1:
            print("1")
        elif a[0]==2:
            print("11")
        elif a[0]==3:
            print("21")
        elif a[0]==4:
            print("31")
        elif a[0]==5:
            print("41")
        elif a[0]==6:
            print("51")
        elif a[0]==7:
            print("61")
        elif a[0]==8:
            print("71")
        elif a[0]==9:
            print("81")
    elif len(a)==2:
        if a[0]==1:
            print("3")
        elif a[0]==2:
            print("13")
        elif a[0]==3:
            print("23")
        elif a[0]==4:
            print("33")
        elif a[0]==5:
            print("43")
        elif a[0]==6:
            print("53")
        elif a[0]==7:
            print("63")
        elif a[0]==8:
            print("73")
        elif a[0]==9:
            print("83")
    elif a[0]==3:
        if a[0]==1:
            print("6")
        elif a[0]==2:
            print("16")
        elif a[0]==3:
            print("26")
        elif a[0]==4:
            print("36")
        elif a[0]==5:
            print("46")
        elif a[0]==6:
            print("56")
        elif a[0]==7:
            print("66")
        elif a[0]==8:
            print("76")
        elif a[0]==9:
            print("86")
    else:
        if a[0]==1:
            print("10")
        elif a[0]==2:
            print("20")
        elif a[0]==3:
            print("30")
        elif a[0]==4:
            print("40")
        elif a[0]==5:
            print("50")
        elif a[0]==6:
            print("60")
        elif a[0]==7:
            print("70")
        elif a[0]==8:
            print("80")
        elif a[0]==9:
            print("90")