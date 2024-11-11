def answer():
    a = int(input())
    c = input()
    b=list(c)
    o,z=0,0


    for x in b:
        if x=="0":z+=1
        else:o+=1
    if o!=z:
        print(len(b))
        print(c)
    else:
        print(2)
        print(c[0],c[1:])
answer()