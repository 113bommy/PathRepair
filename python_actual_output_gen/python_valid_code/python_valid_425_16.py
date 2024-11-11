for _  in range(int(input())):
    a=input()
    ac=bc=cc=0
    for i in a:
        if i=='a':
            ac+=1
        elif i=='b':
            bc+=1 
        elif i=='c':
            cc+=1 
    if ac+cc==bc:
        print("YES")
    else:
        print("NO")