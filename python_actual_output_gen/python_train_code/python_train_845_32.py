r = int(input())
if(r<1):
    print("NO")
elif(r == 1):
    print("NO")
else:
    x = 1
    while(1):
        y = (r -1 -x -x**2)/(2*x)
        if(y<0):
            print("NO")
            break
        if(y//1 == y):
            print(min(x,int(y)),max(x,int(y)))
            break
        x += 1