for i in range(int(input())):
    r,g,b=sorted(list(map(int,input().split())))
    if r+g<=b:
        print(r+g)
    else:
        print((r+g+b)/2)
    