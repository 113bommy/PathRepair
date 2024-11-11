x=int(input())
a,b=map(int,input().split(" "))
c={7:1,17:1,27:1,37:1,47:1,57:1}
jam=0
z=b
while(True):
    try:
        if c[z] == 1:
            print(jam)
            break
    except:
        try:
            if c[a] == 1:
                print(jam+1)
                break
        except:
            jam += 1
            z = z - x
            if z <= 0:
                z = 60 + z
                # print(a)
                a -= 1
                if a<0:
                    a=23
            print(z,a)













