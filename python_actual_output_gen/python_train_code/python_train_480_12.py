n=int(input())
for i in range(n):
    x=input()
    if(x[len(x)-2:len(x)]=="po"):
        print("FILIPINO")
    elif(x[len(x)-4:len(x)]=="desu" or x[len(x)-4:len(x)]=="masa"):
        print("JAPANESE")
    elif(x[len(x)-5:len(x)]=="mnida"):
        print("KOREAN")
    