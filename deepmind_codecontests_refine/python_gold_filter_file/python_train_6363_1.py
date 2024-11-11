def func1(a,b,c,d,e):
    j = max(c, d, e)
    k = min(c, d, e)
    print(j-k+1+abs(b-a))
    for i in range(k,j+1):
        print(str(a)+" "+str(i))
    if a<b:
        for i in range(a+1,b+1):
            print(str(i)+" "+str(e))
    else:
        for i in range(b,a):
            print(str(i)+" "+str(e))

def func2(a,b,c,d,e):
    j = max(c, d, e)
    k = min(c, d, e)
    print(j-k+1+abs(b-a))
    for i in range(k,j+1):
        print(str(i)+" "+str(a))
    if a<b:
        for i in range(a+1,b+1):
            print(str(e)+" "+str(i))
    else:
        for i in range(b,a):
            print(str(e)+" "+str(i))


x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
x3,y3=map(int,input().split())
if x1==x2 and x2==x3:
    a=max(y1,y2,y3)
    b=min(y1,y2,y3)
    print(a-b+1)
    for i in range(b,a+1):
        print(str(x1)+" "+str(i))
elif y1==y2 and y2==y3:
    a=max(x1,x2,x3)
    b=min(x1,x2,x3)
    print(a-b+1)
    for i in range(b,a+1):
        print(str(i)+" "+str(y1))
elif x1==x2:
    func1(x1,x3,y1,y2,y3)
elif x2==x3:
    func1(x2,x1, y2, y3,y1)
elif x1==x3:
    func1(x1,x2, y1,y3,y2)
elif y1==y2:
    func2(y1,y3,x1,x2,x3)
elif y2==y3:
    func2(y2,y1, x2, x3,x1)
elif y1==y3:
    func2(y1,y2, x1,x3,x2)
else:
    l=[(x1,y1),(x2,y2),(x3,y3)]
    l.sort()
    if l[1][1]==max(l[0][1],l[1][1],l[2][1]):
        if l[2][1]-l[0][1]>0:
            print(l[2][0] - l[0][0] + 1 - l[0][1]+l[1][1])
            for i in range(l[0][0], l[2][0]+1):
                print(str(i) + " " + str(l[2][1]))
            for i in range(l[0][1],l[2][1]):
                print(str(l[0][0])+" "+str(i))
            for i in range(l[2][1]+1,l[1][1]+1):
                print(str(l[1][0])+" "+str(i))
        else:
            print(l[2][0] - l[0][0] + 1 - l[2][1] + l[1][1])
            for i in range(l[0][0], l[2][0] + 1):
                print(str(i) + " " + str(l[0][1]))
            for i in range(l[2][1],l[0][1]):
                print(str(l[2][0])+" "+str(i))
            for i in range(l[0][1]+1,l[1][1]+1):
                print(str(l[1][0])+" "+str(i))
    elif l[1][1]==min(l[0][1],l[1][1],l[2][1]):
        if l[2][1]-l[0][1]>0:
            print(l[2][0] - l[0][0] + 1 - l[1][1]+l[2][1])
            for i in range(l[0][0], l[2][0] + 1):
                print(str(i)+ " " + str(l[0][1]))
            for i in range(l[1][1],l[0][1]):
                print(str(l[1][0])+" "+str(i))
            for i in range(l[0][1]+1,l[2][1]+1):
                print(str(l[2][0])+" "+str(i))
        else:
            print(l[2][0] - l[0][0] + 1 - l[1][1] + l[0][1])
            for i in range(l[0][0], l[2][0] + 1):
                print(str(i) + " " + str(l[2][1]))
            for i in range(l[1][1],l[2][1]):
                print(str(l[1][0])+" "+str(i))
            for i in range(l[2][1]+1,l[0][1]+1):
                print(str(l[0][0])+" "+str(i))
    else:
        if l[2][1]-l[0][1]>0:
            print(l[2][0] - l[0][0] + l[2][1] - l[0][1] + 1)
            for i in range(l[0][1], l[1][1]):
                print(str(l[0][0]) + " " + str(i))
            for i in range(l[0][0], l[2][0]):
                print(str(i) + " " + str(l[1][1]))
            for i in range(l[1][1], l[2][1] + 1):
                print(str(l[2][0]) + " " + str(i))
        else:
            print(l[2][0] - l[0][0] + l[0][1] - l[2][1] + 1)
            for i in range(l[2][1], l[1][1]+1):
                print(str(l[2][0]) + " " + str(i))
            for i in range(l[0][0], l[2][0]):
                print(str(i) + " " + str(l[1][1]))
            for i in range(l[1][1]+1, l[0][1] + 1):
                print(str(l[0][0]) + " " + str(i))
