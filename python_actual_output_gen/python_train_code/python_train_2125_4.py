for t in range (int(input())):
    n = int(input())
    x = input()
    a = ""
    b = ""
    try:
        one = x.index("1")
        for i in range(n):
            if (i < one):
                if(x[i] == 2):
                    a += "1"
                    b += "1"
                else:
                    a +="0"
                    b += "0"
            elif (i == one):
                a += "1"
                b += "0"
            else:
                if(x[i] == 2):
                    b += "2"
                elif(x[i] == 1):
                    b += "1"
                else:
                    b += "0"
                a += "0"
    except:
        for i in range(n):
            if(x[i] == "2"):
                a += "1"
                b += "1"
            else:
                a += "0"
                b += "0"
    print(a,"\n"+b)