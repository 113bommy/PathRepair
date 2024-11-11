x=0
for _ in range(int(input())):
    m=input()
    if(m=="x++" or m=="++x"):
        x+=1
    elif(m=="x--" or m=="--x"):
        x-=1
print(x)
    