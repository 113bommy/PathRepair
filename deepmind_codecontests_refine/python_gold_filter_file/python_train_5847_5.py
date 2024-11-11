a=int(input())
red=0
blue=0
li=[]
if a==2:
    input()
    print(11)
else:
    Evenprnths=input()
    for elem in Evenprnths:
        if elem =="(":
            #todo add this to the one having least open parantheses of if draw then red
            if red>blue:
                blue+=1
                print(0,end="")
            else:
                red+=1
                print(1,end="")
        elif elem==")":
            if blue>red:
                blue-=1
                print(0,end="")
            else:
                red-=1
                print(1,end="")


print()
            #todo remove from the one having the most open parantehess

