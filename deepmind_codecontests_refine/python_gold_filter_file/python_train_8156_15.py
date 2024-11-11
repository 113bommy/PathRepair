x,y,a,b=map(int, input().split())

if b+1>x:
    print (0)
else:
    l1=[]

    for i in range(max(b+1,a),x+1):
        for j in range(b,min(i,y+1)):
            l1.append([i,j])

    print (len(l1))

    for i in l1:
        print (i[0],i[1])