a=int(input())
while a:
    l=[]
    b=input()
    if((b.count("X"))>0):
        l.append("1x12")
    if((b[:6].count("X"))>0):
        p=[i for i in range(6) if b[i]=='X']
        for i in p:
            if(b[i:12:6]=='XX'):
                l.append("2x6")
                break
    if((b[:4].count("X"))>0):
        p=[i for i in range(4) if b[i]=='X']
        for i in p:
            if(b[i:12:4]=="XXX"):
                l.append("3x4")
                break
    if((b[:3].count("X"))>0):
        p=[i for i in range(3) if b[i]=='X']
        for i in p:
            if(b[i:12:3]=="XXXX"):
                l.append("4x3")
                break
    if((b[:2].count("X"))>0):
        p=[i for i in range(2) if b[i]=='X']
        for i in p:
            if(b[i:12:2]=="XXXXXX"):
                l.append("6x2")
                break
    if(b.count("X")==12):
        l.append("12x1")
    print(len(l),end=" ")
    if(len(l)>0):
        for i in l:
            print(i,end=" ")
    print("\n")
    a-=1