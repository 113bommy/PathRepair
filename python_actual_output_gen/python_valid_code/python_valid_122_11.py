for _ in " "*int(input()):
    a=int(input());b=input()
    if a==2:
        if b[0]>b[1]:print("YES");print(2);print(b[0],b[1])
        else:print("NO")
    else:print("YES");print(2);print(b[0],b[1:])