name = []
maxi = 0
k = 0
try:
    while 1:
        p = input()
        name.append(p)
        if len(p) > maxi:
            maxi = len(p)
            
except EOFError:
    print("*"*(maxi+2))
    for i in name:
        if (maxi%2 == 0 and len(i)%2 == 1) or(maxi%2 == 1 and len(i)%2 == 0):
            p = maxi-len(i)
            c1 = int(p/2)
            c2 = p-c1
            if k == 0:
                print("*"+ " "*c1+i+" "*c2+"*")
                k = 1
            else:
                print("*"+ " "*c2+i+" "*c1+"*")
                k = 0
        else:
            print("*"+ i.center(maxi," ")+"*")
    print("*"*(maxi+2))
    