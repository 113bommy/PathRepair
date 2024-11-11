n=list(map(int,input().split()))
if n[0]==n[1]:
    print("=")
elif n[0]>2.7 and n[1]>2.7:
    if n[1]>n[0]:
        print(">")
    else:
        print("<")
elif n[0]<2.7 and n[1]<2.7:
    if n[1]>n[0]:
        print("<")
    else:
        print(">")
elif n[0]==1:
    print("<")
elif n[1]==1:
    print(">")
elif n[0]==2:
    if n[1]<4:
        print("<")
    elif n[1]==4:
        print("=")
    else:
        print(">")
elif n[1]==2:
    if n[0]<4:
        print("<")
    elif n[0]==4:
        print("=")
    else:
        print(">")
