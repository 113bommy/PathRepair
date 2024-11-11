n=int(input())
for i in range(n):
    x=input()
    if(x[len(x)-2:len(x)]=="po"):
        print("FILIPINO")
    if(x[len(x)-4:len(x)]=="desu" or x[len(x)-4:len(x)]=="masa"):
        print("JAPANESE")
    if(x[len(x)-5:len(x)]=="mnida"):
        print("KOREAN")
    