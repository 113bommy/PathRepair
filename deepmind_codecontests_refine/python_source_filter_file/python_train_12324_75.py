a=int(input())
x=0
for i in range(a):
    b=input()
    if(b=='x++' or b=="++X"):
        x+=1
    elif(b=="X--" or b=="--X"):
        x-=1
print(x)        