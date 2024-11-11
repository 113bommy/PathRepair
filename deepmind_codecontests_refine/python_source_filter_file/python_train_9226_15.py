z=int(input())
for y in range (z):
    x=int(input())
    small = 3
    big = 7
    t = False
    if x % small ==0 or x % big ==0 :
        print ("yes")
        t = True
    for i in range (1,34):
        if t == True :
            break
        for c in range (1,15):
            if t == True :
                break
            if   (i*small + c*big) == x:
                print ("YES")
                t = True
            elif (i == 33 and c == 14) :
                print ("NO")

