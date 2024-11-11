for _ in range(int(input())):
    x, y=map(int, input().split())
    string=input()
    # x_pos=string.count("R")
    # x_neg=string.count("L")
    # y_pos=string.count("U")
    # y_neg=string.count("D")
    # x_ax=[-x_neg, x_pos]
    # y_ax=[-y_neg, y_pos]
    mx=string.count("R") if x>0 else string.count("L")
    my=string.count("U") if y>0 else string.count("D")
    
    if abs(x)<=mx and abs(y)<=my:
        print("Y")
    else:
        print("N")