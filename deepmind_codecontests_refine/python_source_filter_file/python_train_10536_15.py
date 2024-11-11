for _ in " "*int(input()):
    z=input()
    k=min(z.count("L"),z.count("R"));k1=min(z.count("U"),z.count("D"))
    if k==0:
        if k1:print(2);print("UD")
        else:print(0)
    elif k1==0:
        if k:print(2);print("LR")
        else:print(0)
    else:
        print(2*k+2*k1)
        print("L"*k+"U"*k1+"D"*k1+"R"*k)