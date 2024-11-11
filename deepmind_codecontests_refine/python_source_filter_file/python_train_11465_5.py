for _ in range(int(input())):
    d = int(input())
    b = d*d -4*d
    if(b<0):
        print("N")
    else:
        x = (d+ b**(0.5))/2
        y = (d - b**(0.5))/2
        if(x<0 or y<0):
            print("N")
        else:
            print(x, " ", y)